using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AVS_Coursework_Libr
{
    public partial class Draw : Form
    {
        public Draw()
        {
            InitializeComponent();
        }

        public void MyDrawGraph(double[] ys, double[] xs)
        {
            chart1.Series[0].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Spline;
            chart1.Series[0].YValueMembers = "function";

            chart1.Dock = DockStyle.Fill;
            chart1.ChartAreas[0].AxisX.MajorGrid.Enabled = false;
            chart1.ChartAreas[0].AxisY.MajorGrid.Enabled = false;
            chart1.ChartAreas[0].AxisX.Crossing = 0;
            chart1.ChartAreas[0].AxisY.Crossing = 0;

            chart1.ChartAreas[0].AxisY.Minimum = Math.Round(ys.Min());
            chart1.ChartAreas[0].AxisY.Maximum = Math.Round(ys.Max());
            chart1.ChartAreas[0].AxisX.Minimum = xs.Min();
            chart1.ChartAreas[0].AxisX.Maximum = xs.Max();

            //Chart CA = chart1.ChartAreas[0];  // quick reference
            //CA.AxisX.ScaleView.Zoomable = true;
            //CA.CursorX.AutoScroll = true;
            //CA.CursorX.IsUserSelectionEnabled = true;

            for (int i = 0; i < xs.Length; i++)
            {
                //double y = Math.Sin(xs[i]);
                chart1.Series[0].Points.AddXY( Math.Round(xs[i], 2), Math.Round(ys[i], 3));
            }
        }
    }
}
