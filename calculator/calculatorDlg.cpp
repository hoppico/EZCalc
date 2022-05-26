// calculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"

//#include "iostream.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcalculatorDlg dialog




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CcalculatorDlg::IDD, pParent)
	, m_input(_T(""))
	, output(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_input);
	DDX_Text(pDX, IDC_EDIT2, output);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDCANCEL, &CcalculatorDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_ln, &CcalculatorDlg::OnBnClickedln)
	ON_BN_CLICKED(IDOK, &CcalculatorDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_equal2, &CcalculatorDlg::OnBnClickedequal2)
	ON_BN_CLICKED(IDC_one, &CcalculatorDlg::OnBnClickedone)
	ON_BN_CLICKED(IDC_add, &CcalculatorDlg::OnBnClickedadd)
	ON_BN_CLICKED(IDC_two, &CcalculatorDlg::OnBnClickedtwo)
	ON_BN_CLICKED(IDC_three, &CcalculatorDlg::OnBnClickedthree)
	ON_BN_CLICKED(IDC_four, &CcalculatorDlg::OnBnClickedfour)
	ON_BN_CLICKED(IDC_five, &CcalculatorDlg::OnBnClickedfive)
	ON_BN_CLICKED(IDC_six, &CcalculatorDlg::OnBnClickedsix)
	ON_BN_CLICKED(IDC_seven2, &CcalculatorDlg::OnBnClickedseven2)
	ON_BN_CLICKED(IDC_eight, &CcalculatorDlg::OnBnClickedeight)
	ON_BN_CLICKED(IDC_nine, &CcalculatorDlg::OnBnClickednine)
	ON_BN_CLICKED(IDC_zero, &CcalculatorDlg::OnBnClickedzero)
	ON_BN_CLICKED(IDC_dot, &CcalculatorDlg::OnBnClickeddot)
	ON_BN_CLICKED(IDC_min, &CcalculatorDlg::OnBnClickedmin)
	ON_BN_CLICKED(IDC_mul, &CcalculatorDlg::OnBnClickedmul)
	ON_BN_CLICKED(IDC_div, &CcalculatorDlg::OnBnClickeddiv)
	ON_BN_CLICKED(IDC_sqrt, &CcalculatorDlg::OnBnClickedsqrt)
	ON_BN_CLICKED(IDC_cosin, &CcalculatorDlg::OnBnClickedcosin)
	ON_BN_CLICKED(IDC_sin, &CcalculatorDlg::OnBnClickedsin)
	ON_BN_CLICKED(IDC_tan, &CcalculatorDlg::OnBnClickedtan)
	ON_BN_CLICKED(IDC_log, &CcalculatorDlg::OnBnClickedlog)
	ON_BN_CLICKED(IDC_cotan, &CcalculatorDlg::OnBnClickedcotan)
	ON_BN_CLICKED(IDC_Popen, &CcalculatorDlg::OnBnClickedPopen)
	ON_BN_CLICKED(IDC_Pclose, &CcalculatorDlg::OnBnClickedPclose)
	ON_BN_CLICKED(IDC_bachspase, &CcalculatorDlg::OnBnClickedbachspase)
	ON_BN_CLICKED(IDC_clear, &CcalculatorDlg::OnBnClickedclear)
END_MESSAGE_MAP()


// CcalculatorDlg message handlers

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CcalculatorDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CcalculatorDlg::OnBnClickedln()
{
	m_input += "ln(";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}

class Operator{
public:
	virtual double calculate(double , double=0)=0;
};

/////////////////////////////////////

class mainopr:public Operator{
protected :
	char oprchar;
public:
	static mainopr &makeopr(char);
};

////////////////////////////////////

class mathFunction:public Operator{
protected :
	char fname;
public:
	static mathFunction &makeFunction(char*);
};

////////////////////////////////////

class sumopr:public mainopr{
public:
	double calculate (double x,double y){
		return x+y;
	}

};

/////////////////////////////////

class difopr:public mainopr{
	public:
double calculate (double x,double y){
		return x-y;
	}
};

//////////////////////////////////

class mulopr:public mainopr{
	public:
	double calculate (double x,double y){
		return x*y;
	}

};

//////////////////////////////////

class divopr:public mainopr{
	public:
	double calculate (double x,double y){
			return x/y;
	}

};

//////////////////////////////////

mainopr &mainopr::makeopr(char c){
	mainopr *mopr;
	switch (c){
	case '+':
		mopr=new sumopr;
		break;
	case '-':
		mopr=new difopr;
		break;
	case '*':
		mopr=new mulopr;
		break;
	case '/':
		mopr=new divopr;
		break;
	}
	return *mopr;
}

/////////////////////////////////

class SinFunction:public mathFunction{
public:
	double calculate (double x,double y=0){
		return sin(x*3.141592/(180));
	}
};

/////////////////////////////////

class CosinFunction:public mathFunction{
public:
	double calculate (double x,double y=0){
		return cos(x*3.141592/(180));
	}
};

/////////////////////////////////

class TanFunction:public mathFunction{
public:
	double calculate (double x,double y=0){
		return tan(x*3.141592/(180));
	}
};

/////////////////////////////////

class CotanFunction:public mathFunction{
public:
	double calculate (double x,double y=0){
		return (1/tan(x*3.141592/(180)));
	}
};

/////////////////////////////////

class LnFunction:public mathFunction{
public:
	double calculate (double x,double y=0){
		return log(x);
	}
};

/////////////////////////////////

class LogFunction:public mathFunction{
public:
	double calculate (double x,double y=0){
		return log10(x);
	}
};

////////////////////////////////////

class SqrtFunction:public mathFunction{
public:
	double calculate (double x,double y=0){
		return sqrt(x);
	}
};

/////////////////////////////////

mathFunction &mathFunction::makeFunction(char *function){
	mathFunction *mfunc;
	switch (*(function)){
	case 's':
		if (*(function+1)=='i') mfunc=new SinFunction;
		if (*(function+1)=='q') mfunc=new SqrtFunction;
		break;
	case 't':
		mfunc=new TanFunction;
		break;
	case 'c':
		if (*(function+2)=='s') mfunc=new CosinFunction;
		if (*(function+2)=='t') mfunc=new CotanFunction;
		break;
	case 'l':
		if (*(function+1)=='n') mfunc=new LnFunction;
		if (*(function+1)=='o') mfunc=new LogFunction;
		break;
	}

	return *mfunc;
}

////////////////////////////////

class expression{
public:
	virtual double value ()=0;
};

///////////////////////////////

class branch:public expression{
	Operator &node;
	expression &right,&left;
public:
	branch(char c,expression &r,expression &l):right(r),left(l), node(mainopr::makeopr(c)){}
	branch(char *f,expression &r,expression &l):right(r),left(l),node(mathFunction::makeFunction(f)){}
	double value (){
		return node.calculate(left.value() ,right.value() );
	}
};

////////////////////////////////////

class leaf:public expression{
protected:
	double val;
};

////////////////////////////////////

class number:public leaf{
public:
	number (double x){
		val=x;
	}
	number(char *string){
        val=atof(string);
	}
	double value(){
		return val;
	}
};

////////////////////////////////////

class parser{
	
public:
	char *r(char *temptext,int position);
	char *l(char *temptext,int position);
	expression &makeExpression(char *clactext);
};

//////////////////////////

char *parser::r(char *temptext,int position){
	char *temp;
	int len=0;
	
	len=strlen(temptext);
	temp=new char[len];

	for (int i=0 ; i<len-position-1 ; i++)
		*(temp+i)=*(temptext+position+1+i);

	temp[len-position-1]=0;
	return temp;
}

//////////////////////////

char *parser::l(char *temptext,int position){
	char *temp=new char[position];
	strncpy(temp,temptext,position);

	temp[position]=0;
	
	return temp;
}

//////////////////////////

expression &parser::makeExpression(char *text){
	int pran=0;
	float num=0;
	char opr[4]={'+','-','*','/'};	
	int len=strlen(text);

	while ((*(text)=='(')&&(*(text+len-1)==')')){
		int y=0;
		pran=0;
		for (unsigned int i=0 ; i<strlen(text)-1 ; i++){
			if (*(text+i)=='(') pran++;
			if (*(text+i)==')') pran--;
			if ( (pran==0)) y++;
		}
				
		if (y==0){
			*(text + len - 1)=0;
			text++;
			len=strlen(text);
		}
		else break;
	}

	for(int j=0 ; j<4 ; j++){
		pran=0;
		for (int i=len-1 ; i>=0 ; i--){
			if (*(text+i)=='(') pran++;
			if (*(text+i)==')') pran--;
			if ((*(text+i)==opr[j]) &&(pran==0))
				return *new branch(opr[j],makeExpression(r(text,i)),makeExpression(l(text,i)));
		}
	}

	char *f[]={"sin","cos","tan","cot","log"};	
	for(int j=0 ; j<5 ; j++){
		if (!(strncmp(text,f[j],3))){
			return *new branch(f[j],makeExpression(r(text,2)),makeExpression(r(text,2)));
		}		
	}

	char *f1="ln";
	if (!(strncmp(text,f1,2)))
			return *new branch(f1,makeExpression(r(text,1)),makeExpression(r(text,1)));

	char *f2="sqrt";
	if (!(strncmp(text,f2,4)))
			return *new branch(f2,makeExpression(r(text,3)),makeExpression(r(text,3)));


	return *(new number(text));

}
	
///////////////////////////////

void CcalculatorDlg::OnBnClickedequal2()
{
	UpdateData(true);
	parser x;
	char *s;
	int len=m_input.GetAllocLength();

	//m_input += '\0';
	
	s=new char[len+1];

	for (int i=0 ; i<len ; i++)
		s[i]=m_input[i];
	
	s[len]=0;
	
	expression &y=x.makeExpression(s);
	double n=y.value();
	output=n;
	
	
	delete s;
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedone()
{
	m_input += '1';
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedadd()
{
	m_input += '+';
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedtwo()
{
	m_input += '2';
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedthree()
{
	m_input += '3';
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedfour()
{
	m_input += '4';
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedfive()
{
	m_input += '5';
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedsix()
{
	m_input += '6';
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedseven2()
{
	m_input += '7';
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedeight()
{
	m_input += '8';
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickednine()
{
	m_input += '9';
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedzero()
{
	m_input += '0';
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickeddot()
{
	m_input += '.';
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedmin()
{
	m_input += '-';
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedmul()
{
	m_input += '*';
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickeddiv()
{
	m_input += '/';
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedsqrt()
{
	m_input += "sqrt(";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedcosin()
{
	m_input += "cos(";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedsin()
{
	m_input += "sin(";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedtan()
{
	m_input += "tan(";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedlog()
{
	m_input += "log(";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedcotan()
{
	m_input += "cot(";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedPopen()
{
	m_input += '(';
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedPclose()
{m_input += ')';
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedbachspase()
{
	UpdateData(true);
	m_input.Delete(m_input.GetLength()-1);
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedclear()
{
	UpdateData(true);
	m_input.Empty();
	UpdateData(false);
}
