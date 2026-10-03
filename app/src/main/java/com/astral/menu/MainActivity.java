package com.astral.menu;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.provider.Settings;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.SeekBar;

public class MainActivity extends Activity {
    @Override
    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.menu);

        CheckBox ff = findViewById(R.id.fastFire);
        ff.setOnCheckedChangeListener((v, on) -> NativeBridge.setFeature(4, on));

        CheckBox ia = findViewById(R.id.infAmmo);
        ia.setOnCheckedChangeListener((v, on) -> NativeBridge.setFeature(5, on));

        CheckBox ws = findViewById(R.id.wallshot);
        ws.setOnCheckedChangeListener((v, on) -> NativeBridge.setFeature(6, on));

        CheckBox nr = findViewById(R.id.noRecoil);
        nr.setOnCheckedChangeListener((v, on) -> NativeBridge.setFeature(7, on));

        CheckBox os = findViewById(R.id.oneShot);
        os.setOnCheckedChangeListener((v, on) -> NativeBridge.setFeature(8, on));

        CheckBox fp = findViewById(R.id.fastPlant);
        fp.setOnCheckedChangeListener((v, on) -> NativeBridge.setFeature(9, on));

        SeekBar ar = findViewById(R.id.aspectRatio);
        ar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            public void onProgressChanged(SeekBar s, int p, boolean u) {
                NativeBridge.setFloat(2, p / 10.0f);
            }
            public void onStartTrackingTouch(SeekBar s) {}
            public void onStopTrackingTouch(SeekBar s) {}
        });

        Button start = findViewById(R.id.btnStart);
        start.setOnClickListener(v -> {
            if (Build.VERSION.SDK_INT >= 23 && !Settings.canDrawOverlays(this)) {
                startActivity(new Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION,
                        Uri.parse("package:" + getPackageName())));
                return;
            }
            startService(new Intent(this, MenuService.class));
            finish();
        });
    }
}
