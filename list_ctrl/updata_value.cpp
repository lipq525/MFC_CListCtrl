// updata_value.cpp: 实现文件
//

#include "pch.h"
#include "list_ctrl.h"
#include "updata_value.h"
#include "afxdialogex.h"
#include "list_ctrlDlg.h"


// updata_value 对话框

IMPLEMENT_DYNAMIC(updata_value, CDialogEx)

updata_value::updata_value(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_new_value, pParent)
	, m_value_2(_T(""))
{

}

updata_value::~updata_value()
{
}

 BOOL updata_value::OnInitDialog()
{
	 SetDlgItemText(IDC_EDIT1_2_value, m_value_2);
	 return TRUE;
}
void updata_value::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1_2_value, m_value_2);
}


BEGIN_MESSAGE_MAP(updata_value, CDialogEx)
	ON_BN_CLICKED(IDOK, &updata_value::OnBnClickedOk)
END_MESSAGE_MAP()


// updata_value 消息处理程序


void updata_value::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	ClistctrlDlg * parent = (ClistctrlDlg*)GetParent();
	
	int nNowRow = parent->m_list.GetSelectionMark();//获取父列表当前被选中的列序号
 //
	CString value = L"";
	GetDlgItemText(IDC_EDIT1_2_value, value);//获取用户输入的内容
	//
	//
	//
	//
	
	/*CString str;
	str = this->m_value_2;*/
	parent->m_list.SetItemText(nNowRow, 1, value);//写入某行第二列内容信息

	CDialogEx::OnOK();

}
