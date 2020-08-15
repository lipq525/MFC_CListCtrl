#pragma once

// updata_value 对话框

class updata_value : public CDialogEx
{
	DECLARE_DYNAMIC(updata_value)

public:
	updata_value(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~updata_value();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_new_value };
#endif

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_value_2;
	afx_msg void OnBnClickedOk();
};
