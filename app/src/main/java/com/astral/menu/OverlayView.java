package com.astral.menu;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.view.View;

public class OverlayView extends View {
    private Paint paint = new Paint();

    public OverlayView(Context c) {
        super(c);
        paint.setColor(0xFF39FF14);
        paint.setStrokeWidth(3f);
    }

    @Override protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        // ESP boxes — coordinates from native
    }
}
