//���崴��~����1ֱ�����ô���Textout��ɫ���壬������������ṹָ�룬����2��ԭ�ͷš�
typedef struct TDFONT
{
	HFONT hOldFont;
	HFONT hFont;
}TDFONT,*LPTDFONT;

#define BLUE RGB(100,149,237)
#define VIOLET RGB(138,43,226)



LPTDFONT ChangeFontTd(HDC hdc,long height)
{
	LOGFONT logfont;
	ZeroMemory(&logfont,sizeof(LOGFONT));
	logfont.lfCharSet=GB2312_CHARSET;
	logfont.lfHeight=height;
	HFONT hFont=CreateFontIndirect(&logfont);
	HFONT hOldFont=(HFONT)::SelectObject(hdc,hFont);
	LPTDFONT pFont= new TDFONT;
	(*pFont).hOldFont=hOldFont;
	(*pFont).hFont=hFont;
	return pFont;
}
int DeleteFontTd(HDC hdc,LPTDFONT pFont)
{
    SelectObject(hdc,(*pFont).hOldFont);
    DeleteObject((*pFont).hFont);
	delete pFont;
	return 0;
}


//���Ժ���ErrorBox.
void ErrorBox(HWND hwnd)
{
DWORD wrongitem=GetLastError();
char wrong[10];
sprintf(wrong,"%d",wrongitem);
MessageBox(hwnd,wrong,"wrong",MB_YESNO|MB_ICONQUESTION|MB_DEFBUTTON1|MB_SYSTEMMODAL);
}

//������Ϣ����
void MessageBoxTD(HWND hwnd,LPCTSTR lpCaption)
{
   MessageBox(hwnd,lpCaption,"��������",MB_YESNO|MB_ICONQUESTION|MB_DEFBUTTON1|MB_SYSTEMMODAL);
}

void MessageBoxTD(HWND hwnd,LPCTSTR lpText,LPCTSTR lpTitle)
{
   MessageBox(hwnd,lpText,lpTitle,MB_YESNO|MB_ICONQUESTION|MB_DEFBUTTON1|MB_SYSTEMMODAL);
}


//��Ϸ��ʼ������WM_PAINT �趨��
/* case ID_CREATE:
                    GameTD(hwnd);  
					PicTD(hwnd);
					  break;*/
#define ID_CREATE 1001
int GameTD(HWND hwnd)
{
	static int NeedPaint=0;
	int xpos,ypos;
	mciSendString("open .\\music\\begin.MP3 alias mymusic", NULL, 0, NULL);
    mciSendString("play mymusic repeat", NULL, 0, NULL);
	if(NeedPaint==1)return 0;
	HDC dc=GetDC(hwnd);
	SetBkMode(dc,TRANSPARENT);
    HBRUSH hBrush=::CreateSolidBrush(RGB(127,255,212));
	::SelectObject(dc,hBrush);
	Rectangle(dc,0,0,HENG,SHU);
	for(xpos=0;xpos<=HENG;xpos++)
	{
		for(ypos=0;ypos<350;ypos++)
		SetPixel(dc,xpos,ypos,BLUE);
	    for(ypos=350;ypos<=SHU;ypos++)
		SetPixel(dc,xpos,ypos,VIOLET);
	}
	HPEN hPen=CreatePen(0,PS_NULL,0);
	SelectObject(dc,hPen);
	LPTDFONT OldFont1=ChangeFontTd(dc,100);
	::SetTextColor(dc,ORANGE);
	TextOut(dc,20,50,"Loading...",10);
	DeleteFontTd(dc,OldFont1);
	LPTDFONT OldFont=ChangeFontTd(dc,200);
	for(xpos=HENG;xpos>=0;xpos--)
	{
		if((HENG-xpos)<=20)	
		Rectangle(dc,xpos,0,HENG,SHU);
		else
			Rectangle(dc,xpos,0,xpos+20,SHU);
		if(xpos<=750)
			{
				::SetTextColor(dc,BLUE);
				TextOut(dc,320,150,"T",1);
				TextOut(dc,620,150,"D",1);
				::SetTextColor(dc,VIOLET);
				TextOut(dc,320,350,"GAME",4);
			}
		}
		DeleteFontTd(dc,OldFont);
		ReleaseDC(hwnd,dc);
		NeedPaint=1;
        DeleteObject(hBrush);
		DeleteObject(hPen);
		return 0;
}


void PicTD(HWND hwnd)
{
    HDC dc=GetDC(hwnd);
	SetBkMode(dc,TRANSPARENT);
	HBRUSH hBrush=::CreateSolidBrush(RGB(127,255,212));
	::SelectObject(dc,hBrush);
	Rectangle(dc,0,0,HENG,SHU);
	LPTDFONT OldFont=ChangeFontTd(dc,200);
	::SetTextColor(dc,BLUE);
	TextOut(dc,320,150,"T",1);
	TextOut(dc,620,150,"D",1);
	::SetTextColor(dc,VIOLET);
	TextOut(dc,320,350,"GAME",4);
	SetTextColor(dc,ORANGE);
	DeleteFontTd(dc,OldFont);
	LPTDFONT OldFont2=ChangeFontTd(dc,120);
	TextOut(dc,400,550,"PLAY",4);
	DeleteFontTd(dc,OldFont);
	ReleaseDC(hwnd,dc);
}
//�������
#include<time.h>
#define MAX 10000
int GetRandomNumber()
{
    srand(GetTickCount());
    int number = rand();
    return number;
}

int GetRandomNumber2()
{
    srand(GetTickCount()+2378);
    int number = rand();
    return number;
}

int GetRandomNumber3()
{
int Random;
srand( (unsigned)time( NULL ) );//srand()��������һ���Ե�ǰʱ�俪ʼ���������.Ӧ�÷���for��ѭ�����ǰ�� ��ȻҪ�ܳ�ʱ��ȴ�
Random=rand()%MAX;//MAXΪ���ֵ���������Ϊ0~MAX-1
return Random;
}


/////////////////�򵥿�ͼ
int QuickBlt(LPCTSTR PicID,HINSTANCE hInstance,HDC hdc1,HDC hdc2)
{
		BITMAP bmp;
		HBITMAP hBmp;
		hBmp=LoadBitmap(hInstance,PicID);
		HGDIOBJ hOldSel;
		hOldSel=SelectObject(hdc1,hBmp);
		GetObject(hBmp,sizeof(bmp),&bmp);
		BitBlt(hdc2,0,0,bmp.bmWidth,bmp.bmHeight,hdc1,0,0,SRCCOPY);
		SelectObject(hdc1,hOldSel);
		DeleteObject(hBmp);
		return 0;
}
int QuickTransparentBlt(LPCTSTR PicID,HINSTANCE hInstance,HDC hdc1,HDC hdc2)
{
		BITMAP bmp;
		HBITMAP hBmp;
		hBmp=LoadBitmap(hInstance,PicID);
		HGDIOBJ hOldSel;
		hOldSel=SelectObject(hdc1,hBmp);
		GetObject(hBmp,sizeof(bmp),&bmp);
		TransparentBlt(hdc2,0,0,bmp.bmWidth,bmp.bmHeight,hdc1,0,0,bmp.bmWidth,bmp.bmHeight,RGB(0,0,0));
		SelectObject(hdc1,hOldSel);
		DeleteObject(hBmp);
		return 0;
}/////�����Ͻǵ�
