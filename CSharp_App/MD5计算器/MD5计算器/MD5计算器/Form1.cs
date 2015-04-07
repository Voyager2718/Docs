using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Security.Cryptography;

namespace MD5计算器
{
    public partial class Form1 : Form
    {
        public string GetMd5(string Source)
        {
            MD5 md5 = MD5.Create();
            byte[] data = md5.ComputeHash(Encoding.UTF8.GetBytes(Source));
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < data.Length; i++)
            {
                sb.Append(data[i].ToString("x2"));//将每一个位加起来
            }
            return sb.ToString();
        }

        public string GetSha256(string Source)
        {
            SHA256Managed crypt = new SHA256Managed();
            string hash = String.Empty;
            byte[] crypto = crypt.ComputeHash(Encoding.ASCII.GetBytes(Source), 0, Encoding.ASCII.GetByteCount(Source));
            foreach (byte bit in crypto)
            {
                hash += bit.ToString("x2");
            }
            return hash;
        }

        public Form1()
        {
            InitializeComponent();
            textBox1.Text = "md5";
            textBox2.Text = "MD5";
            textBox3.Text = "SHA256";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string text = richTextBox1.Text.ToString();
            textBox1.Text = GetMd5(text);
            textBox2.Text = textBox1.Text.ToUpper();
            textBox3.Text = GetSha256(text);
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
                this.TopMost = true;
        }
    }
}
