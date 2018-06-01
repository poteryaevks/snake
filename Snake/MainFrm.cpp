
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
	: Draw(&m_Osnake)
{
	// TODO: add member initialization code here
	get_started = false;
	gameover = false;
}

 CMainFrame::~CMainFrame()
{
	// TODO: add member initialization code here
	
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
	CBrush brush_black(RGB(0, 0, 0));
	CBrush brush_brawn(RGB(148, 77, 77));
	
	if (get_started)
	{
			
						 
			do //хвост змеи
				{
				
					/*TRACE("Addr: %x\n", temp);
					TRACE("Count: %d\n", temp->get_count());
					TRACE("pNext: %d\n", temp->pNext);

					TRACE("right: %d\n", temp->rect.right);
					TRACE("left: %d\n", temp->rect.left);

					TRACE("top: %d\n", temp->rect.top);
					TRACE("bottom: %d\n", temp->rect.bottom);*/
					dc.FillRect(temp->rect, &brush_brawn);
					temp = temp->pNext;
			} while (temp);

			dc.FillRect(&m_Osnake.rect, &brush_black);  //голова змейки
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
	eMoveto moveto;
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
			moveto = right;
			if (m_Osnake.get_direction() != left)
				add_tail(moveto);
			
		}

		if (nFlags == MOVE_LEFT)
		{
			moveto = left;
			if (m_Osnake.get_direction() != right )
				add_tail(moveto);
		}

		if (nFlags == MOVE_TOP)
		{
			moveto = top;
			if (m_Osnake.get_direction() != top )
				add_tail(moveto);
		}

		if (nFlags == MOVE_BOTTOM)
		{
			moveto = bottom;
			if (m_Osnake.get_direction() != top )
				add_tail(moveto);
		}

	}
	
	CFrameWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}



void CMainFrame::add_tail(eMoveto to)
{
	if (to != m_Osnake.get_direction())
	{
		Draw.AddElem(&m_Osnake, m_Osnake.get_direction(), to);
	}
	m_Osnake.set_direction(to);
}




void ComputeThreadProc(CMainFrame* mfrm)
{
	while (true)
	{
		mfrm->Draw.ChangeRect(&mfrm->m_Osnake);
		Sleep(200);
		mfrm->PostMessageW(WM_USERAPPLY);

	}
	
}