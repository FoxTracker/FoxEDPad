package com.foxelectron.foxedpad;


import android.os.Bundle;
import android.preference.PreferenceActivity;

/**
 * Created by Adrian on 26.11.2016.
 */

public class AppPreferences extends PreferenceActivity
{


    @Override protected void onCreate(Bundle savedInstanceState)
        {
        super.onCreate(savedInstanceState);
        addPreferencesFromResource(R.xml.app_preferences);
        }
}
