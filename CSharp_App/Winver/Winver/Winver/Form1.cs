using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Winver
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            int MainVer = System.Environment.OSVersion.Version.Major;
            int SecVer = System.Environment.OSVersion.Version.Minor;
            string Label = "0";
            if (MainVer >= 6 && SecVer >= 3)
            {
                Label = "您的系统是Windows 8.1/Windows Server 2012R2或更高版本\n\n";
            }
            if (MainVer == 6 && SecVer == 2)
            {
                Label = "您的系统是Windows 8/Windows Server 2012\n\n";
            }
            if (MainVer == 6 && SecVer == 1)
            {
                Label = "您的系统是Windows 7/Windows Server 2008R2\n\n";
            }
            if (MainVer == 6 && SecVer == 0)
            {
                Label = "您的系统是Windows Vista/Windows Server 2008\n\n";
            }
            if (MainVer == 5 && SecVer == 2)
            {
                Label = "您的系统是Windows XP 64Bit/Windows Server 2003/\nWindows Server 2003R2\n\n";
            }
            if (MainVer == 5 && SecVer == 1)
            {
                Label = "您的系统是Windows XP\n\n";
            }
            if (MainVer == 5 && SecVer == 0)
            {
                Label = "您的系统是Windows 2000\n\n";
            }
            if (MainVer < 5)
            {
                Label = "您的系统是Windows 2000以前的系统\n\n";
            }
            Version version = System.Environment.Version;
            Label = Label + "Microsoft NT " + MainVer.ToString() + "." + SecVer.ToString();
            label1.Text = Label;
        }
        int Times = 1;
        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            Times++;
            if (Times > 20)
            {
                MessageBox.Show("作者：杨志鹏\n版本：1.0", "Version");
                Times = 0;
            }
        }
    }
}
