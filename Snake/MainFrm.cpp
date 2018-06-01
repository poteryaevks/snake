
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Snake.h"
#include "MainFrm.h"
#include "SnakeView.h"
#include "CObjectSnake.h"
#include "DrawTail.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

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
	: brush_black(RGB(0, 0, 0)),
      brush_brawn(RGB(148, 77, 77))
{
	// TODO: add member initialization code here
	get_started = false;
	gameover = false;
	m_pOSsnake = new CObjectSnake;
}

 CMainFrame::~CMainFrame()
{
	// TODO: add member initialization code here
	 delete m_pOSsnake;
}


 LRESULT CMainFrame::OnUserApply(WPARAM wParam, LPARAM IParam)
 {
	 //TRACE(_T("\nUserApply\n"));
	 this->Invalidate();
	 return 0;
 }


BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CFrameWnd::PreCreateWindow(cs))
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//the CREATESTRUCT cs
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
	CTail* temp = Draw.pSnake_tail.pFirst; 
	
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CFrameWnd::OnPaint() for painting messages
	
	
	if (get_started)
	{
			dc.FillRect(&m_pOSsnake->rect, &brush_black);  //голова змейки
						 
			while ( temp->pNext ) //хвост змеи
				{
					temp = temp->pNext;
					/*TRACE("Addr: %x\n", temp);
					TRACE("Count: %d\n", temp->get_count());
					TRACE("pNext: %d\n", temp->pNext);

					TRACE("right: %d\n", temp->rect.right);
					TRACE("left: %d\n", temp->rect.left);

					TRACE("top: %d\n", temp->rect.top);
					TRACE("bottom: %d\n", temp->rect.bottom);*/
					dc.FillRect(temp->rect, &brush_brawn);
				}
	}
	else
	{
		dc.TextOut(195, 200, _T("Press Enter to start"));
	}

	
}


void CMainFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CWinThread* pThread;

	if (!get_started)
	{
		if (nFlags == START)
		{
			get_started = true;

			pThread = AfxBeginThread((AFX_THREADPROC)ComputeThreadProc, this);
		}
	
	}
	else
	{
		if (nFlags == MOVE_RIGHT)
		{
			if( m_pOSsnake->get_direction() != left )
				m_pOSsnake->set_direction( right );
		}

		if (nFlags == MOVE_LEFT)
		{
			if ( m_pOSsnake->get_direction() != right ) 
			m_pOSsnake->set_direction( left );
		}

		if (nFlags == MOVE_TOP)
		{
			if ( m_pOSsnake->get_direction() != top )
			m_pOSsnake->set_direction( top );
		}

		if (nFlags == MOVE_BOTTOM)
		{
			if ( m_pOSsnake->get_direction() != top )
			m_pOSsnake->set_direction( bottom );
		}

	}
	
	CFrameWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void ComputeThreadProc(CMainFrame* pMainFrm)
{
	
	// процесс обработки в новом топоке
	while (!pMainFrm->gameover)
	{ 
		//движение головы змейки 
		if (pMainFrm->m_pOSsnake->get_direction() == top)
		{
			pMainFrm->m_pOSsnake->move_top();
		}
        
		if (pMainFrm->m_pOSsnake->get_direction() == bottom)
		{
			pMainFrm->m_pOSsnake->move_bottom();
		}

		if (pMainFrm->m_pOSsnake->get_direction() == right)
		{
			pMainFrm->m_pOSsnake->move_right();
		}

		if(pMainFrm->m_pOSsnake->get_direction() == left)
		{
			pMainFrm->m_pOSsnake->move_left();
		}



		Sleep(700);
		pMainFrm->PostMessageW(WM_USERAPPLY);
	}
}

