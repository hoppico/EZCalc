// calculatorDlg.h : header file
//

#pragma once


// CcalculatorDlg dialog
class CcalculatorDlg : public CDialog
{
// Construction
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
public:
	CString m_input;
public:
	afx_msg void OnBnClickedln();
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnBnClickedequal2();
public:
	afx_msg void OnBnClickedone();
public:
	afx_msg void OnBnClickedadd();
public:
	double output;
public:
	afx_msg void OnBnClickedtwo();
public:
	afx_msg void OnBnClickedthree();
public:
	afx_msg void OnBnClickedfour();
public:
	afx_msg void OnBnClickedfive();
public:
	afx_msg void OnBnClickedsix();
public:
	afx_msg void OnBnClickedseven2();
public:
	afx_msg void OnBnClickedeight();
public:
	afx_msg void OnBnClickednine();
public:
	afx_msg void OnBnClickedzero();
public:
	afx_msg void OnBnClickeddot();
public:
	afx_msg void OnBnClickedmin();
public:
	afx_msg void OnBnClickedmul();
public:
	afx_msg void OnBnClickeddiv();
public:
	afx_msg void OnBnClickedsqrt();
public:
	afx_msg void OnBnClickedcosin();
public:
	afx_msg void OnBnClickedsin();
public:
	afx_msg void OnBnClickedtan();
public:
	afx_msg void OnBnClickedlog();
public:
	afx_msg void OnBnClickedcotan();
public:
	afx_msg void OnBnClickedPopen();
public:
	afx_msg void OnBnClickedPclose();
public:
	afx_msg void OnBnClickedbachspase();
public:
	afx_msg void OnBnClickedclear();
};
