package com.foxelectron.foxedpad;

import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v4.app.FragmentActivity;
import android.view.WindowManager;


public class MainActivity extends AppCompatActivity {

    Fragment_EDTab_Fight fightFragment;
    @Override protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);


        FragmentManager manager = getSupportFragmentManager();
        FragmentTransaction transaction = manager.beginTransaction();
        fightFragment = new Fragment_EDTab_Fight();
        transaction.add(R.id.activity_main, fightFragment);
        transaction.commit();


    }


    @Override public void onBackPressed()   //Suppress back button
        {
        //moveTaskToBack(true);
        }
}
