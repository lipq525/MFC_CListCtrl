
// list_ctrlDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "list_ctrl.h"
#include "list_ctrlDlg.h"
#include "afxdialogex.h"
#include "updata_value.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ClistctrlDlg 对话框



ClistctrlDlg::ClistctrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LIST_CTRL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ClistctrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	/*DDX_Control(pDX, IDC_LIST2, m_list_2);*/
}

BEGIN_MESSAGE_MAP(ClistctrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &ClistctrlDlg::OnNMDblclkList1)
END_MESSAGE_MAP()


// ClistctrlDlg 消息处理程序

BOOL ClistctrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//////////
	CRect rect;
	CWnd *wnd = NULL;
	wnd = GetDlgItem(IDC_LIST1);
	if (NULL == wnd)
	{
		MessageBox(_T("相应控件不存在"));
	}
	///
	LONG lStyle;
	lStyle = GetWindowLong(m_list.m_hWnd, GWL_STYLE);//获取当前窗口style
	lStyle &= ~LVS_TYPEMASK; //清除显示方式位
	lStyle |= LVS_REPORT; //设置style
	SetWindowLong(m_list.m_hWnd, GWL_STYLE, lStyle);//设置style

	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl）
	dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl）
	//dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件
	m_list.SetExtendedStyle(dwStyle); //设置扩展风格
	///
	wnd->GetWindowRect(&rect);
	ScreenToClient(&rect);
	int width = ((int)rect.right - (int)rect.left) / 3;
	m_list.InsertColumn(0, _T("key"), LVCFMT_CENTER, width, -1);// 插入列 
	m_list.InsertColumn(1, _T("value"), LVCFMT_CENTER, width, -1);
	m_list.InsertColumn(2, _T("描述"), LVCFMT_CENTER, width, -1);
	

	///////
	//m_list.SetTextColor(RGB(0, 0, 255));
	////m_list.SetExtendedStyle( LVS_EX_GRIDLINES | LVS_EX_INFOTIP);
	//m_list.InsertColumn(0, _T("Day"), LVCFMT_CENTER, 55);
	//m_list.InsertColumn(1, _T("Name"), LVCFMT_CENTER, 100);



	m_list.InsertItem(0, _T("Day1"));
	m_list.SetItemText(0, 1, _T("Monday"));
	m_list.SetItemText(0, 2, _T("hhhhh"));
	//
	m_list.InsertItem(1, _T("Day2"));
	m_list.SetItemText(1, 1, _T("Tuesday"));
	m_list.SetItemText(1, 2, _T("kkkkk"));

	m_list.InsertItem(2, _T("Day3"));
	m_list.SetItemText(2, 1, _T("Wednesday"));
	m_list.SetItemText(2, 2, _T("tttt"));
	



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void ClistctrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void ClistctrlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR ClistctrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void ClistctrlDlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	CString key = _T(""), value = _T(""), des = _T("");
	//1.获取list当前所指向的行编号
	//2.获得该行下的每一个str
	//3.将获得的str传递给子窗口
	int nowRow = m_list.GetSelectionMark();
	key = m_list.GetItemText(nowRow, 0);
	value = m_list.GetItemText(nowRow, 1);
	des = m_list.GetItemText(nowRow, 2);
	
	updata_value* dlg = new updata_value(this);

	dlg->m_value_2 = value;
	dlg->Create(IDD_DIALOG_new_value, this);
	dlg->ShowWindow(SW_SHOW);




}
