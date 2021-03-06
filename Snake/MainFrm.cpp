
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Snake.h"
#include "MainFrm.h"
#include "SnakeView.h"
#include "CObjectSnake.h"
#include "DrawTail.h"
#include "TimeControll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


std::condition_variable foo;
std::mutex mtx;

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_MESSAGE(WM_USERAPPLY, OnUserApply)
	ON_WM_PAINT()
//	ON_WM_XBUTTONDBLCLK()
	ON_WM_XBUTTONDOWN()
	ON_WM_NCXBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame construction/destruction

CMainFrame::CMainFrame()
	: m_Ddraw(&m_Osnake),
	  get_started(FALSE),
	  m_bGameover(FALSE)
{
	// рамка
	frame[0].SetRect(0, 0, 480, 20);
	frame[1].SetRect(0, 420, 480, 440);
	frame[2].SetRect(0, 0, 20, 440);
	frame[3].SetRect(460, 0, 480, 440);

	//кисти
	m_pbrush_black = new CBrush(RGB(0, 0, 0));
	m_pbrush_brawn = new CBrush(RGB(148, 77, 77));
	m_prush_red = new CBrush(RGB(214, 26, 26));
}

 CMainFrame::~CMainFrame()
{
	 delete m_pbrush_black;
	 delete m_pbrush_brawn;
	 delete m_prush_red;
}


 LRESULT CMainFrame::OnUserApply(WPARAM wParam, LPARAM IParam)
 {
	  this->Invalidate();
	 return 0;
 }


BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CFrameWnd::PreCreateWindow(cs))
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	
	cs.cx = 500;
	cs.cy = 500;
	
	cs.style = FWS_ADDTOTITLE | WS_SYSMENU | WS_CAPTION | WS_OVERLAPPED | WS_MINIMIZEBOX;
	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers
void CMainFrame::OnPaint()
{
	
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CFrameWnd::OnPaint() for painting messages
	
	dc.FillRect(&frame[0], m_prush_red);
	dc.FillRect(&frame[1], m_prush_red);
	dc.FillRect(&frame[2], m_prush_red);
	dc.FillRect(&frame[3], m_prush_red);

	if ( get_started )
	{
		CTail* temp = m_Tlist->first;
			do //хвост змеи
				{
					dc.FillRect(temp->get_rect(), m_pbrush_brawn);
					temp = temp->pNext;
				} while (temp);

			dc.FillRect(&m_Osnake.get_rect(), m_pbrush_black);  //голова змейки
			
			

	}
	if ( !get_started && !m_bGameover )
		dc.TextOut(195, 200, _T("Press Enter to start"));
	
	if ( m_bGameover ) 
		dc.TextOut(195, 200, _T("You lose.."));

	foo.notify_one();
	Sleep(300);
}



void CMainFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CWinThread* pThread;
		
		if ( !get_started )
	{
		if (nFlags == START)
		{
			pThread = AfxBeginThread((AFX_THREADPROC)ComputeThreadProc, this);
			get_started = TRUE;
		}
	}
	else
	{
		if ( tc.time_get() >= 0.12 )
		{
			if (nFlags == MOVE_RIGHT)
			{
				foo.notify_one();
				if (m_Osnake.get_direction() != left)
					m_Osnake.set_direction(right);

			}

			if (nFlags == MOVE_LEFT)
			{
				foo.notify_one();
				if (m_Osnake.get_direction() != right)
					m_Osnake.set_direction(left);
			}

			if (nFlags == MOVE_TOP)
			{
				foo.notify_one();
				if (m_Osnake.get_direction() != top)
					m_Osnake.set_direction(top);
			}

			if (nFlags == MOVE_BOTTOM)
			{
				foo.notify_one();
				if (m_Osnake.get_direction() != top)
					m_Osnake.set_direction(bottom);
			}
			tc.reset();
		}
		
	}
	CFrameWnd::OnKeyDown(nChar, nRepCnt, nFlags);
	
}


void ComputeThreadProc(CMainFrame* mfrm)
{
	TIME_START;
	bool flag = FALSE;
	while (!mfrm->m_bGameover)
		{
			if ( ( TIME_GET >= 0.1 ) 
				|| (flag == FALSE) )
				{
					mfrm->m_Ddraw.on_idle(&mfrm->m_Osnake, &mfrm->m_Tlist, &mfrm->m_bGameover);
					flag = TRUE;
					TIME_START;
				}
			mfrm->PostMessageW(WM_USERAPPLY);
			
			foo.wait(std::unique_lock<std::mutex>(mtx));
		}
	
}