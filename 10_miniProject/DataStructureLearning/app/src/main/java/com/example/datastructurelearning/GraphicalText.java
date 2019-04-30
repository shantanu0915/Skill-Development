package com.example.datastructurelearning;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.view.View;

public class GraphicalText extends View {
    int x,y;
    String text;
    int color;
    Paint paint = new Paint();

    public GraphicalText(Context context, int x, int y, String text, int color) {
        super(context);
        this.x = x;
        this.y = y;
        this.text = text;
        this.color = color;
    }

    @Override
    protected void onDraw(Canvas canvas) {
        paint.setColor(color);
        paint.setTextSize(40);
        canvas.drawText(text,x,y,paint);
    }
}
