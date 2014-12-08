package edu.sjtu.stap.monday.graphics;

public class GameLibJNIWrapper {
    static {
        System.loadLibrary("game");
    }
 
    public static native void on_surface_created();
 
    public static native void on_surface_changed(int width, int height);
 
    public static native void on_draw_frame();
    
    public static native void draw_two_eye(MRender mRender, int screenheight, int screenwidth);
    
}
