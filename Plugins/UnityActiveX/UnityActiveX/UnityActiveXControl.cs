using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace UnityActiveX
{
    public partial class UnityActiveXControl : UserControl
    {
        AxUnityWebPlayerAXLib.AxUnityWebPlayer UnityWebPlayer;

        public UnityActiveXControl()
        {
            InitializeComponent();

            AxUnityWebPlayerAXLib.AxUnityWebPlayer.CheckForIllegalCrossThreadCalls = true;
            UnityActiveX.UnityActiveXControl.CheckForIllegalCrossThreadCalls = true;

            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(UnityActiveXControl));

            string path = Environment.GetCommandLineArgs()[0]; 
            string dirpath = path.Substring(0, path.LastIndexOf('\\')); 

            UnityWebPlayer = new AxUnityWebPlayerAXLib.AxUnityWebPlayer(dirpath + "\\UnityWebAgent\\UnityWebAgent.unity3d");

            UnityWebPlayer.BeginInit();

            this.SuspendLayout();

            UnityWebPlayer.Enabled = true;
            UnityWebPlayer.Location = new System.Drawing.Point(0, -10);
            UnityWebPlayer.Name = "axUnityWebPlayer1";
            UnityWebPlayer.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axUnityWebPlayer1.OcxState")));
            UnityWebPlayer.Size = new System.Drawing.Size(493, 391);
            UnityWebPlayer.TabIndex = 0;

            this.Controls.Add(UnityWebPlayer);

            UnityWebPlayer.EndInit();

            this.ResumeLayout(false);

            UnityWebPlayer.OnExternalCall += new AxUnityWebPlayerAXLib._DUnityWebPlayerAXEvents_OnExternalCallEventHandler(UnityWebPlayer_OnExternalCall);


        }

        void UnityWebPlayer_OnExternalCall(object sender, AxUnityWebPlayerAXLib._DUnityWebPlayerAXEvents_OnExternalCallEvent e)
        {
            
        }
       
    }
}
