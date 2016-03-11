using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinForms
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private async void button1_Click(object sender, EventArgs e)
        {
            var str = "两个黄鹂鸣翠柳，\r\n一行白鹭上青天。";
            uiTextBox.Text = "";
            foreach (var ch in str)
            {
                uiTextBox.Text += ch;
                // Thread.Sleep(200);
                // Update();
                await Task.Delay(200);
            }
        }
    }
}
