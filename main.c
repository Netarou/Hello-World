#include "test.h"

/*
    �ŏI�I�Ɏg�����͂���Ȋ����ɂȂ�܂�
*/
int main(void)
{
    
    Interface* Interface = CreateInterface( 1024, 512 );
    Interface->PrintData( Interface );
    ReleaseInterface( Interface );
    
    return 0;
}

/*	�����܂�	*/