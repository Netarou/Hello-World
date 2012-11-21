#include "test.h"

/*
    ÅI“I‚ÉŽg‚¤‘¤‚Í‚±‚ñ‚ÈŠ´‚¶‚É‚È‚è‚Ü‚·
*/
int main(void)
{
    
    Interface* Interface = CreateInterface( 1024, 512 );
    Interface->PrintData( Interface );
    ReleaseInterface( Interface );
    
    return 0;
}

/*	‚±‚±‚Ü‚Å	*/