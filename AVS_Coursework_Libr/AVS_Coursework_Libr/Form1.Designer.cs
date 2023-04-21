using System.Runtime.InteropServices;

namespace AVS_Coursework_Libr
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.textA = new System.Windows.Forms.TextBox();
            this.textB = new System.Windows.Forms.TextBox();
            this.textStep = new System.Windows.Forms.TextBox();
            this.textFunct = new System.Windows.Forms.TextBox();
            this.butComplete = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(58, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Введите а";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 38);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(58, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Введите в";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 68);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(71, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Введите шаг";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(12, 101);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(97, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "Введите функцию";
            // 
            // textA
            // 
            this.textA.Location = new System.Drawing.Point(143, 1);
            this.textA.Name = "textA";
            this.textA.Size = new System.Drawing.Size(100, 20);
            this.textA.TabIndex = 4;
            // 
            // textB
            // 
            this.textB.Location = new System.Drawing.Point(143, 38);
            this.textB.Name = "textB";
            this.textB.Size = new System.Drawing.Size(100, 20);
            this.textB.TabIndex = 5;
            // 
            // textStep
            // 
            this.textStep.Location = new System.Drawing.Point(143, 68);
            this.textStep.Name = "textStep";
            this.textStep.Size = new System.Drawing.Size(100, 20);
            this.textStep.TabIndex = 6;
            // 
            // textFunct
            // 
            this.textFunct.Location = new System.Drawing.Point(143, 101);
            this.textFunct.Name = "textFunct";
            this.textFunct.Size = new System.Drawing.Size(100, 20);
            this.textFunct.TabIndex = 7;
            // 
            // butComplete
            // 
            this.butComplete.Location = new System.Drawing.Point(15, 144);
            this.butComplete.Name = "butComplete";
            this.butComplete.Size = new System.Drawing.Size(228, 23);
            this.butComplete.TabIndex = 8;
            this.butComplete.Text = "Complete";
            this.butComplete.UseVisualStyleBackColor = true;
            this.butComplete.Click += new System.EventHandler(this.butComplete_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(283, 202);
            this.Controls.Add(this.butComplete);
            this.Controls.Add(this.textFunct);
            this.Controls.Add(this.textStep);
            this.Controls.Add(this.textB);
            this.Controls.Add(this.textA);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textA;
        private System.Windows.Forms.TextBox textB;
        private System.Windows.Forms.TextBox textStep;
        private System.Windows.Forms.TextBox textFunct;
        private System.Windows.Forms.Button butComplete;
    }
}

