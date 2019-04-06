using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

      private void button1_Click(object sender, EventArgs e)
        {
            ServiceReference1.sendmailClient ws = new ServiceReference1.sendmailClient();
            string r = ws.sendEmail("752256693@qq.com","123456789");
        
        }
    }
}
