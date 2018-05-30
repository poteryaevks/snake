
// MainFrm.h : interface of the CMainFrame class
//
#include "SnakeView.h"

#pragma once
class CSnakeView;

#define WM_USERAPPLY WM_USER + 5

#define MOVE_RIGHT 333
#define MOVE_LEFT 331 
#define MOVE_TOP 328
#define MOVE_BOTTOM 336
#define START 28


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
	CObjectSnake* m_pOSsnake;
	
	
	
// Implementation
public:
	virtual ~CMainFrame();
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	bool  gameover;
protected:  // control bar embedded members
	CStatusBar m_wndStatusBar;
	CSnakeView m_CView_Snk;
		
	bool get_started;
	


// Generated message map functions
protected:
	


	DECLARE_MESSAGE_MAP()

public:
	afx_msg LRESULT OnUserApply(WPARAM wParam, LPARAM IParam);
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};


void ComputeThreadProc(CMainFrame* pMainFrm);
