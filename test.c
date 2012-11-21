#include "test.h"
#include <stdio.h>
#include <stdlib.h>

/*
    以下のように実装用の構造体を用意すると
    メンバ変数を外部から隠蔽できるようになります。
*/

typedef struct Implements
{
	/*
		インターフェイス構造体メンバを必ず先頭にします（理由は生成関数の実装で。）
		ちなみにポインタにしない理由もそちらで。
	*/
    Interface Interface;
    int x,y;                /*  適当に  */
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
		実装した関数のアドレスはここで入れます
		インターフェイス構造体をなぜ実装構造体のトップに配置したのかは、
		メモリ上のオフセットを揃えたいからです。
		（実装メンバ関数内でキャストしてメンバ変数のデータを取り出すため）
		ポインタにしてもいいのですが、インターフェイスの分を
		またmallocで確保する手間を考えると素直に実体をメンバにしたほうが楽です。
	*/

    impl->Interface.PrintData = &_PrintData;
    
    /*  データメンバの初期化はここで行います（引数を省略してるなら0とか入れときます */
    impl->x = x;
    impl->y = y;
    
    /*  あくまで使う側にはメンバ関数しか触らせない    */
    return ( Interface* )impl;
}
 
void ReleaseInterface(struct Interface* Interface)
{
    free( Interface );
}
 
/*
	メンバ関数の実装
	staticにすると外部のファイルからは見えなくなります
*/

static void _PrintData(struct Interface* Interface)
{
    /*
    「先頭がInterfaceポインタ」と約束している（オフセットが決まっている）為合法。
    こうすることによって実装構造体はクラスみたいにメンバ変数などはprivateにできます。
    */
    Implements* impl = ( Implements* )Interface;
    
    /* この関数の処理内容はデータメンバの内容を書きだして終わりです。   */
    printf( "( %d, %d )\n",  impl->x,  impl->y ); 
}
/*  ここまで    */
