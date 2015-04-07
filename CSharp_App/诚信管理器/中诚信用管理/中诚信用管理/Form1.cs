using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Finisar.SQLite;

namespace 中诚信用管理
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            string path = @"config.ini";
            if (System.IO.File.Exists(path))
            {
                string[] size = System.IO.File.ReadAllLines(path, Encoding.UTF8);
                this.Size = new Size(Int32.Parse(size[3]), Int32.Parse(size[2]));
                if (size[1] == "True")
                {
                    Size = new Size(720, 450);
                    WindowState = FormWindowState.Maximized;
                }
            }
        }

        private void 退出ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Form1_SizeChanged(object sender, EventArgs e)
        {
            dataGridView1.Height = Size.Height - 79;
            dataGridView1.Width = Size.Width - 41;
            bool maxi = false;
            if (WindowState == FormWindowState.Maximized)
                maxi = true;
            string[] size = { "请勿修改此文件", maxi.ToString(), Size.Height.ToString(), Size.Width.ToString() };
            System.IO.File.WriteAllLines(@"config.ini", size, Encoding.UTF8);
        }

        private void 测试ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Form1:" + Size.Width + " " + Size.Height + "\nDGV:" + dataGridView1.Width + " " + dataGridView1.Height + "\nDGV Posi:" + dataGridView1.Location.X + " " + dataGridView1.Location.Y, "窗口大小");
        }

        private void 关于ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("中诚信用管理系统\n版本：0.0.1.0001\n\n长乐科技", "关于");
        }

        private void 窗口置顶ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (TopMost == true)
            {
                TopMost = false;
                窗口置顶ToolStripMenuItem.Text = "窗口置顶";
            }
            else
            {
                TopMost = true;
                窗口置顶ToolStripMenuItem.Text = "窗口置顶 √";
            }
        }

        private void 文档选项OToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 form2 = new Form2();
            if (TopMost == true)
                form2.TopMost = true;
            form2.ShowDialog();
            form2.Focus();
        }

        private void 打开ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string db_Path;
            OpenFileDialog OFD = new OpenFileDialog();
            OFD.Filter = "Database(*.db)|*.db";
            OFD.ShowDialog();
            db_Path = OFD.FileName;


            // [snip] - As C# is purely object-oriented the following lines must be put into a class:

            // We use these three SQLite objects:
            SQLiteConnection sqlite_conn;
            SQLiteCommand sqlite_cmd;
            SQLiteDataReader sqlite_datareader;

            // create a new database connection:
            sqlite_conn = new SQLiteConnection("Data Source=db.db;Version=3;New=True;Compress=True;");

            // open the connection:
            sqlite_conn.Open();

            // create a new SQL command:
            sqlite_cmd = sqlite_conn.CreateCommand();

            // Let the SQLiteCommand object know our SQL-Query:
            sqlite_cmd.CommandText = "CREATE TABLE test (id integer primary key, text varchar(100));";

            // Now lets execute the SQL ;D
            sqlite_cmd.ExecuteNonQuery();

            // Lets insert something into our new table:
            sqlite_cmd.CommandText = "INSERT INTO test (id, text) VALUES (1, 'Test Text 1');";

            // And execute this again ;D
            sqlite_cmd.ExecuteNonQuery();

            // ...and inserting another line:
            sqlite_cmd.CommandText = "INSERT INTO test (id, text) VALUES (2, 'Test Text 2');";

            // And execute this again ;D
            sqlite_cmd.ExecuteNonQuery();

            // But how do we read something out of our table ?
            // First lets build a SQL-Query again:
            sqlite_cmd.CommandText = "SELECT * FROM test";

            // Now the SQLiteCommand object can give us a DataReader-Object:
            sqlite_datareader = sqlite_cmd.ExecuteReader();

            // The SQLiteDataReader allows us to run through the result lines:
            while (sqlite_datareader.Read()) // Read() returns true if there is still a result line to read
            {
                // Print out the content of the text field:
                //System.Console.WriteLine(sqlite_datareader["text"]);
                string MyReader = sqlite_datareader.GetString(0);//0的意思是第一行的数据
                MessageBox.Show(MyReader);
            }

            // We are ready, now lets cleanup and close our connection:
            sqlite_conn.Close();


        }

        private void 另存为ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string db_Path;
            SaveFileDialog SFD = new SaveFileDialog();
            SFD.Filter = "Database(*.db)|*.db";
            SFD.ShowDialog();
            db_Path = SFD.FileName;
        }
    }
}
