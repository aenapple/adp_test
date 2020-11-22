#include "mserial.h"
#include <windows.h>


boolean MSerial::Open(char port[], DWORD BaudRate, BYTE ByteSize,
                                                   BYTE Parity, BYTE StopBits, WORD TimeOut)
{
    handle = CreateFile
                    (
                     port,
                     GENERIC_READ | GENERIC_WRITE,
                     NULL,
                     NULL,
                     OPEN_EXISTING,
                     FILE_FLAG_OVERLAPPED,
                     NULL
                    );

    if(handle == INVALID_HANDLE_VALUE) {return FALSE; }
    if(!SetupComm(handle, SizeBuffer, SizeBuffer)) {return FALSE; }
    if(!GetCommState(handle, &dcb)) {return FALSE; }

    dcb.BaudRate           = BaudRate;
    dcb.fBinary            = TRUE;
    dcb.fOutxCtsFlow       = FALSE;
    dcb.fOutxDsrFlow       = FALSE;
    dcb.fDtrControl        = DTR_CONTROL_DISABLE;//DTR_CONTROL_ENABLE;//    //DTR_CONTROL_HANDSHAKE;
    dcb.fDsrSensitivity    = FALSE;
    dcb.fNull              = FALSE;
	dcb.fRtsControl        = RTS_CONTROL_DISABLE;     //!!!
	//dcb.fRtsControl        = RTS_CONTROL_DISABLE; //RTS_CONTROL_ENABLE;//     //!!!

    /*
    RTS_CONTROL_TOGGLE Задает, что сигнал RTS установлен, когда есть данные для передачи.
    Когда все символы из передающего буфера переданы, сигнал сбрасывается.
    */
    
    dcb.fAbortOnError      = FALSE;
    dcb.ByteSize           = ByteSize;
    dcb.Parity	           = Parity;
    dcb.StopBits           = StopBits;

    if(!SetCommState(handle, &dcb)){return FALSE; }
    if(!GetCommTimeouts(handle, &CommTimeOuts)) {return FALSE; }

    CommTimeOuts.ReadIntervalTimeout         = TimeoutInterval;
    CommTimeOuts.ReadTotalTimeoutMultiplier  = TimeoutChar;
    CommTimeOuts.ReadTotalTimeoutConstant    = TimeOut;
    CommTimeOuts.WriteTotalTimeoutMultiplier = 0;
    CommTimeOuts.WriteTotalTimeoutConstant   = 0;

    if(!SetCommTimeouts(handle, &CommTimeOuts)) {return FALSE; }
    
    memset(&Overlap,0,sizeof(Overlap));
    Overlap.hEvent=CreateEvent(NULL,TRUE,FALSE,NULL);


    ResetRB();
    ResetWB();
    return TRUE;
};

void MSerial::Close(void)
{
    CloseHandle(handle);
    CloseHandle(Overlap.hEvent);
}

unsigned short MSerial::Read(BYTE *buffer, unsigned short numbytes)
{
    DWORD temp;
    ClearCommError(handle, &temp, &ComState);
    if (!temp)
    {
//        memset(&Overlap,0,sizeof(Overlap));
//        Overlap.hEvent=CreateEvent(NULL,TRUE,FALSE,NULL);
        ReadFile(handle,buffer, numbytes, &temp, &Overlap);
        GetOverlappedResult(handle, &Overlap, &temp, true);
    }
    return (unsigned short)temp;
}

unsigned short MSerial::Write(void *buffer, unsigned short numbytes)
{
    DWORD temp;
    if(numbytes)
    {
        ClearCommError(handle, &temp, &ComState);
        if((numbytes + ComState.cbOutQue)>=SizeBuffer)
          MessageBox(NULL, "Невозможно поместить в выходной буфер ", "", MB_OK);

//        memset(&Overlap,0,sizeof(Overlap));
//        Overlap.hEvent=CreateEvent(NULL,TRUE,FALSE,NULL);
        boolean result=WriteFile(handle, buffer, numbytes, &temp, &Overlap);
        GetOverlappedResult(handle, &Overlap, &temp, true);
        if(result)
        {
           return (unsigned short)temp;
        }
    }
    return 0;
}

void MSerial::ResetRB(void)
{
    PurgeComm(handle, PURGE_RXCLEAR);
}

void MSerial::ResetWB(void)
{
    PurgeComm(handle, PURGE_TXCLEAR);
}

unsigned short MSerial::GetWBSize(void)
{
   DWORD temp;
   ClearCommError(handle, &temp, &ComState);
   return (unsigned short) ComState.cbOutQue;
}

unsigned short MSerial::GetRBSize(void)
{
   DWORD temp;
   ClearCommError(handle, &temp, &ComState);
   return (unsigned short) ComState.cbInQue;
}


void MSerial::Set_DTR_RTS(void)
{
    EscapeCommFunction(handle, SETDTR);
    EscapeCommFunction(handle, SETRTS);  
}


void MSerial::Clr_DTR_RTS(void)
{
    EscapeCommFunction(handle, CLRDTR);
    EscapeCommFunction(handle, CLRRTS);
}

void MSerial::Set_RTS(void)
{
    EscapeCommFunction(handle, SETRTS);
}


void MSerial::Clr_RTS(void)
{
    EscapeCommFunction(handle, CLRRTS);
}

void MSerial::Set_DTR(void)
{
    EscapeCommFunction(handle, SETDTR);
}


void MSerial::Clr_DTR(void)
{
    EscapeCommFunction(handle, CLRDTR);
}

