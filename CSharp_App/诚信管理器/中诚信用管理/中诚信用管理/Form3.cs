using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace 中诚信用管理
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void Form3_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Escape)
                this.Close();
            else if (e.KeyCode == Keys.W && e.Modifiers == Keys.Control)
                this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void panel1_MouseHover(object sender, EventArgs e)
        {
            this.panel1.Focus();
        }

        private void groupBox4_MouseHover(object sender, EventArgs e)
        {
            this.panel1.Focus();
        }

    }
}
