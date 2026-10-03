package com.astral.menu;

public class NativeBridge {
    static { System.loadLibrary("astral"); }
    public static native void init(int pid);
    public static native void setFeature(int id, boolean on);
    public static native void setFloat(int id, float val);
}
