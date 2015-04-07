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
            textBox2.PasswordChar = '\0';
        }

        private void button1_MouseUp(object sender, MouseEventArgs e)
        {
            textBox2.PasswordChar = '*';
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
        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "" || textBox2.Text == "")
                textBox3.Text = "Please fill in all the blanks .";
            else
            {
                string Total = textBox1.Text + textBox2.Text, Hash = "";
                Hash = GetMd5(Total);
                int Times = 0;
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
                textBox3.Text = Times.ToString();
                for (int j = 0; j < Times; j++)
                    Hash = GetMd5(Total);
                textBox3.Text = Hash.Substring(14);
            }
        }
    }
}
