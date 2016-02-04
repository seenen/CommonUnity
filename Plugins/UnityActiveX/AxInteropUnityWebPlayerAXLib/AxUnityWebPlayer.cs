namespace AxUnityWebPlayerAXLib
{
    using System;
    using System.ComponentModel;
    using System.Runtime.CompilerServices;
    using System.Runtime.InteropServices;
    using System.Windows.Forms;
    using UnityWebPlayerAXLib;
    using System.Collections;
    using System.Reflection;
    using System.Text;

    [DefaultEvent("OnExternalCall"), DesignTimeVisible(true), Clsid("{444785f1-de89-4295-863a-d46c3a781394}")]
    public class AxUnityWebPlayer : AxHost
    {
        private string DynaSRC;
        private AxHost.ConnectionPointCookie cookie;
        private AxUnityWebPlayerEventMulticaster eventMulticaster;
        private _DUnityWebPlayerAX ocx;

        public event AxUnityWebPlayerAXLib._DUnityWebPlayerAXEvents_OnExternalCallEventHandler OnExternalCall;

        public event AxUnityWebPlayerAXLib._DUnityWebPlayerAXEvents_ReadyStateChangeEventHandler ReadyStateChange;

        public AxUnityWebPlayer(string src) : base("444785f1-de89-4295-863a-d46c3a781394")
        {
            DynaSRC = src;
        }

        protected override void AttachInterfaces()
        {
            try
            {
                this.ocx = (_DUnityWebPlayerAX)base.GetOcx();
                this.ocx.src = DynaSRC;

            }
            catch (Exception)
            {

            }
        }

        protected override void CreateSink()
        {
            try
            {
                this.eventMulticaster = new AxUnityWebPlayerEventMulticaster(this);
                this.cookie = new AxHost.ConnectionPointCookie(this.ocx, this.eventMulticaster, typeof(_DUnityWebPlayerAXEvents));
            }
            catch (Exception)
            {
            }
        }

        protected override void DetachSink()
        {
            try
            {
                this.cookie.Disconnect();
            }
            catch (Exception)
            {
            }
        }

        public virtual string GetPluginVersion()
        {
            if (this.ocx == null)
            {
                throw new AxHost.InvalidActiveXStateException("GetPluginVersion", AxHost.ActiveXInvokeKind.MethodInvoke);
            }
            return this.ocx.GetPluginVersion();
        }

        public virtual string GetUnityVersion(string release)
        {
            if (this.ocx == null)
            {
                throw new AxHost.InvalidActiveXStateException("GetUnityVersion", AxHost.ActiveXInvokeKind.MethodInvoke);
            }
            return this.ocx.GetUnityVersion(release);
        }

        internal void RaiseOnOnExternalCall(object sender, _DUnityWebPlayerAXEvents_OnExternalCallEvent e)
        {
            if (this.OnExternalCall != null)
            {
                this.OnExternalCall(sender, e);
            }
        }

        internal void RaiseOnReadyStateChange(object sender, _DUnityWebPlayerAXEvents_ReadyStateChangeEvent e)
        {
            if (this.ReadyStateChange != null)
            {
                this.ReadyStateChange(sender, e);
            }
        }

        public virtual void SendMessage(string obj, string method, object val)
        {
            if (this.ocx == null)
            {
                throw new AxHost.InvalidActiveXStateException("SendMessage", AxHost.ActiveXInvokeKind.MethodInvoke);
            }
            this.ocx.SendMessage(obj, method, val);
        }

        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden), DispId(-525)]
        public virtual int readyState
        {
            get
            {
                if (this.ocx == null)
                {
                    throw new AxHost.InvalidActiveXStateException("readyState", AxHost.ActiveXInvokeKind.PropertyGet);
                }
                return this.ocx.readyState;
            }
        }

        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden), DispId(1)]
        public virtual string src
        {
            get
            {
                if (this.ocx == null)
                {
                    throw new AxHost.InvalidActiveXStateException("src", AxHost.ActiveXInvokeKind.PropertyGet);
                }
                return this.ocx.src;
            }
            set
            {
                if (this.ocx == null)
                {
                    throw new AxHost.InvalidActiveXStateException("src", AxHost.ActiveXInvokeKind.PropertySet);
 
                }
                this.ocx.src = value;
            }
        }

        //[DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden), DispId(666)]
        //public virtual string disableContextMenu
        //{
        //    get
        //    {
        //        if (this.ocx == null)
        //        {
        //            throw new AxHost.InvalidActiveXStateException("disableContextMenu", AxHost.ActiveXInvokeKind.PropertyGet);
        //        }
        //        return this.ocx.disableContextMenu;
        //    }
        //    set
        //    {
        //        if (this.ocx == null)
        //        {
        //            throw new AxHost.InvalidActiveXStateException("disableContextMenu", AxHost.ActiveXInvokeKind.PropertySet);

        //        }
        //        this.ocx.disableContextMenu = value;
        //    }
        //}


    }
}

