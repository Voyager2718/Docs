using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Security.Cryptography;

namespace Multi_Password
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_MouseDown(object sender, MouseEventArgs e)
        {
            textBox3.PasswordChar = '\0';
        }

        private void button1_MouseUp(object sender, MouseEventArgs e)
        {
            textBox3.PasswordChar = '*';
        }
        string GetMd5(string Source)
        {
            MD5 md5 = MD5.Create();
            string Hash = "";
            byte[] s = md5.ComputeHash(Encoding.UTF8.GetBytes(Source));
            for (int i = 0; i < s.Length; i++)
            {
                Hash = Hash + s[i].ToString("X");
            }
            return Hash;
        }
        int PressTimes = 0;
        private void button2_Click(object sender, EventArgs e)
        {
            PressTimes++;
            if (textBox1.Text == "" || textBox3.Text == "" || textBox2.Text == "")
                textBox4.Text = "Please fill in all the blanks .";
            else
            {
                string T1Website = textBox1.Text;
                if (textBox1.Text.Length >= 8)
                {
                    if (textBox1.Text.Substring(0, 7) == "http://")
                        T1Website = textBox1.Text.Substring(7);
                    else if (textBox1.Text.Substring(0, 8) == "https://")
                        T1Website = textBox1.Text.Substring(8);
                }

                if (T1Website.Substring(T1Website.Length - 1, 1) == "/")
                    T1Website = T1Website.Substring(0, T1Website.Length - 1);

                string Total = T1Website + textBox3.Text+textBox2.Text, Hash = "";

                Hash = GetMd5(Total);

                int Times = 10;
                for (int i = 0; i < 16; i++)
                {
                    char[] c;
                    c = (Hash.Substring(i, i + 1)).ToCharArray();
                    if (c[0] >= '0' || c[0] <= '9')
                    {
                        Times = c[0];
                        break;
                    }
                }
                textBox4.Text = Times.ToString();
                for (int j = 0; j < Times; j++)
                    Hash = GetMd5(Total);
                textBox4.Text = Hash.Substring(0, 16);
            }
            if (PressTimes >= 20)
            {
                MessageBox.Show("Author:YANG Zhipeng \nVersion v1.2.2.1 \nAlgorithm v1.2");
                PressTimes = 0;
            }
            if (checkBox1.Checked == true && textBox4.Text!="Please fill in all the blanks .")
                Clipboard.SetDataObject(textBox4.Text);
        }

        private void VisitLink()
        {
            linkLabel1.LinkVisited = true;
            System.Diagnostics.Process.Start("http://goo.gl/H7rcct");
        }
        private void linkLabel1_Click(object sender, EventArgs e)
        {
            try
            {
                VisitLink();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Unable to open link that was clicked.");
            }
        }

        private void linkLabel2_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel1.LinkVisited = true;
            System.Diagnostics.Process.Start("http://weibo.com/536449338");
        }
    }
}
