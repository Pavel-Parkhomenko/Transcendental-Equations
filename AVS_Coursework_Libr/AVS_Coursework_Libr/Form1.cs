using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AVS_Coursework_Libr
{
    public partial class Form1 : Form
    {
        [DllImport(@"D:\Документы Д\Programms\Courseworks\AVS (CouseWork)\AVS_Coursework_Libr\Debug\MethodLibrary.dll", EntryPoint = "?GetInterval@@YGXPANH@Z", CallingConvention = CallingConvention.StdCall)]
        static extern void GetInterval([In, MarshalAs(UnmanagedType.LPArray)] double[] arr, int len);
        [DllImport(@"D:\Документы Д\Programms\Courseworks\AVS (CouseWork)\AVS_Coursework_Libr\Debug\MethodLibrary.dll", EntryPoint = "?SetFunc@@YGXPADH@Z", CallingConvention = CallingConvention.StdCall)]
        static extern void SetFunct(string sb, int len);
        [DllImport(@"D:\Документы Д\Programms\Courseworks\AVS (CouseWork)\AVS_Coursework_Libr\Debug\MethodLibrary.dll", EntryPoint = "?PointsYS@@YGXPANH@Z", CallingConvention = CallingConvention.StdCall)]
        static extern void PointsYS([In, MarshalAs(UnmanagedType.LPArray)] double[] arr, int len);
        [DllImport(@"D:\Документы Д\Programms\Courseworks\AVS (CouseWork)\AVS_Coursework_Libr\Debug\MethodLibrary.dll", EntryPoint = "?SetAttribute@@YGXNNN@Z", CallingConvention = CallingConvention.StdCall)]
        static extern void SetAtrribute(double a, double b, double eps);
        //static extern void GetArr([In, MarshalAs(UnmanagedType.LPArray)] double[] arr, int len);
        double a;
        double b;
        double eps;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void butComplete_Click(object sender, EventArgs e)
        {
            a = double.Parse(textA.Text);
            b = double.Parse(textB.Text);
            eps = double.Parse(textStep.Text);
            string funct = textFunct.Text;

            funct = "(" + funct + ")";
            double[] arr = new double[10];

            SetAtrribute(a, b, eps);
            SetFunct(funct, funct.Length);
            GetInterval(arr, arr.Length);
            if (arr == null)
            {
                MessageBox.Show("нет корней");
            }
            else
            {
                DrawGraph();
                MessageBox.Show(arr[0].ToString() + "   " + arr[1].ToString());
            }
        }

        private void DrawGraph()
        {
            int cnt = (int)((b - a) / eps) + 1;
            double[] pointsYS = new double[cnt];
            PointsYS(pointsYS, cnt);
            double[] xs = new double[cnt];
            int j = 0;
            for(double i = a; i < b; i += eps)
            {
                xs[j] = i;
                j++;
            }

            Draw draw = new Draw();
            draw.MyDrawGraph(pointsYS, xs);
            draw.Show();
            //this.Close();
        }
    }
}
