#include "test.h"
#include <stdio.h>
#include <stdlib.h>

/*
    �ȉ��̂悤�Ɏ����p�̍\���̂�p�ӂ����
    �����o�ϐ����O������B���ł���悤�ɂȂ�܂��B
*/

typedef struct Implements
{
	/*
		�C���^�[�t�F�C�X�\���̃����o��K���擪�ɂ��܂��i���R�͐����֐��̎����ŁB�j
		���Ȃ݂Ƀ|�C���^�ɂ��Ȃ����R��������ŁB
	*/
    Interface Interface;
    int x,y;                /*  �K����  */
}Implements;

static void _PrintData( struct Interface* );

Interface* CreateInterface(int x, int y)
{
    Implements* impl = ( Implements* )malloc( sizeof( Implements ) );
	
	if( impl == NULL )
	{
		exit(1);
	}
    
	/*
		���������֐��̃A�h���X�͂����œ���܂�
		�C���^�[�t�F�C�X�\���̂��Ȃ������\���̂̃g�b�v�ɔz�u�����̂��́A
		��������̃I�t�Z�b�g�𑵂���������ł��B
		�i���������o�֐����ŃL���X�g���ă����o�ϐ��̃f�[�^�����o�����߁j
		�|�C���^�ɂ��Ă������̂ł����A�C���^�[�t�F�C�X�̕���
		�܂�malloc�Ŋm�ۂ����Ԃ��l����Ƒf���Ɏ��̂������o�ɂ����ق����y�ł��B
	*/

    impl->Interface.PrintData = &_PrintData;
    
    /*  �f�[�^�����o�̏������͂����ōs���܂��i�������ȗ����Ă�Ȃ�0�Ƃ�����Ƃ��܂� */
    impl->x = x;
    impl->y = y;
    
    /*  �����܂Ŏg�����ɂ̓����o�֐������G�点�Ȃ�    */
    return ( Interface* )impl;
}
 
void ReleaseInterface(struct Interface* Interface)
{
    free( Interface );
}
 
/*
	�����o�֐��̎���
	static�ɂ���ƊO���̃t�@�C������͌����Ȃ��Ȃ�܂�
*/

static void _PrintData(struct Interface* Interface)
{
    /*
    �u�擪��Interface�|�C���^�v�Ɩ񑩂��Ă���i�I�t�Z�b�g�����܂��Ă���j�׍��@�B
    �������邱�Ƃɂ���Ď����\���̂̓N���X�݂����Ƀ����o�ϐ��Ȃǂ�private�ɂł��܂��B
    */
    Implements* impl = ( Implements* )Interface;
    
    /* ���̊֐��̏������e�̓f�[�^�����o�̓��e�����������ďI���ł��B   */
    printf( "( %d, %d )\n",  impl->x,  impl->y ); 
}
/*  �����܂�    */
