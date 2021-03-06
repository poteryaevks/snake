
// MainFrm.h : interface of the CMainFrame class
//
#pragma once

#include "SnakeView.h"
#include "CObjectSnake.h"
#include "DrawTail.h"
#include "TimeControll.h"

class CSnakeView;
class CObjectSnake;
class CDrawTail;

#define WM_USERAPPLY WM_USER + 5

#define MOVE_RIGHT 333
#define MOVE_LEFT 331 
#define MOVE_TOP 328
#define MOVE_BOTTOM 336
#define START 28


class timecontroll;

class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame();
	protected: 
	DECLARE_DYNAMIC(CMainFrame)

// Attributes
protected:
	CSplitterWnd m_wndSplitter;
public:

// Operations
public:

// Overrides
public:
	
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
	timecontroll tc;
	CObjectSnake m_Osnake;
	CTailList* m_Tlist;
	CDrawTail m_Ddraw;
	
// Implementation
public:
	virtual ~CMainFrame();
	bool  m_bGameover;
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	
protected:  // control bar embedded members
	CStatusBar m_wndStatusBar;
	CSnakeView m_CView_Snk;
	
	bool get_started;
	
	CRect frame[4];//рамка 

// Generated message map functions
protected:
	
	DECLARE_MESSAGE_MAP()

	CBrush* m_pbrush_black;
	CBrush* m_pbrush_brawn;
	CBrush* m_prush_red;


public:
	afx_msg LRESULT OnUserApply(WPARAM wParam, LPARAM IParam);
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};


void ComputeThreadProc(CMainFrame* mfrm);
