package com.example.datastructurelearning;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.View;

public class GraphicsLine extends View {

    Paint paint = new Paint();
    int x1,y1,x2,y2;
    int color;

    public GraphicsLine(Context context, int x1, int y1, int x2, int y2, int color) {
        super(context);
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
        this.color = color;
    }

    @Override
    protected void onDraw(Canvas canvas) {

        paint.setStyle(Paint.Style.STROKE);
        paint.setColor(color);
        paint.setStrokeWidth(5);
        canvas.drawLine(x1,y1,x2,y2,paint);
    }
}
