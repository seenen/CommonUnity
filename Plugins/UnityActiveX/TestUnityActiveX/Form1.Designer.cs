﻿namespace TestUnityActiveX
{
    partial class Form1
    {
        /// <summary>
        /// Variable nécessaire au concepteur.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Nettoyage des ressources utilisées.
        /// </summary>
        /// <param name="disposing">true si les ressources managées doivent être supprimées ; sinon, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Code généré par le Concepteur Windows Form

        /// <summary>
        /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
        /// le contenu de cette méthode avec l'éditeur de code.
        /// </summary>
        private void InitializeComponent()
        {
            this.unityActiveXControl1 = new UnityActiveX.UnityActiveXControl();
            this.SuspendLayout();
            // 
            // unityActiveXControl1
            // 
            this.unityActiveXControl1.Location = new System.Drawing.Point(12, 12);
            this.unityActiveXControl1.Name = "unityActiveXControl1";
            this.unityActiveXControl1.Size = new System.Drawing.Size(640, 480);
            this.unityActiveXControl1.TabIndex = 0;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(744, 548);
            this.Controls.Add(this.unityActiveXControl1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private UnityActiveX.UnityActiveXControl unityActiveXControl1;
    }
}

