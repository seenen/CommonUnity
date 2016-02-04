namespace AxUnityWebPlayerAXLib
{
    using System;
    using System.Runtime.InteropServices;
    using UnityWebPlayerAXLib;

    [ClassInterface(ClassInterfaceType.None)]
    public class AxUnityWebPlayerEventMulticaster : _DUnityWebPlayerAXEvents
    {
        private AxUnityWebPlayer parent;

        public AxUnityWebPlayerEventMulticaster(AxUnityWebPlayer parent)
        {
            this.parent = parent;
        }

        public virtual void OnExternalCall(string value)
        {
            _DUnityWebPlayerAXEvents_OnExternalCallEvent e = new _DUnityWebPlayerAXEvents_OnExternalCallEvent(value);
            this.parent.RaiseOnOnExternalCall(this.parent, e);
        }

        public virtual void ReadyStateChange(int readyState)
        {
            _DUnityWebPlayerAXEvents_ReadyStateChangeEvent e = new _DUnityWebPlayerAXEvents_ReadyStateChangeEvent(readyState);
            this.parent.RaiseOnReadyStateChange(this.parent, e);
        }
    }
}

