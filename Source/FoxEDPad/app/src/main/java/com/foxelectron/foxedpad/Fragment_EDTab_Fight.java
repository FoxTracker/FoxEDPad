package com.foxelectron.foxedpad;

import android.app.Activity;
import android.content.Context;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.net.Network;
import android.net.Uri;
import android.os.Bundle;
import android.os.Debug;
import android.os.StrictMode;
import android.preference.PreferenceManager;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v7.app.AlertDialog;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import 	android.widget.Button;
import android.util.Log;
import android.content.Intent;



/**
 * A simple {@link Fragment} subclass.
 * Activities that contain this fragment must implement the
 * {@link Fragment_EDTab_Fight.OnFragmentInteractionListener} interface
 * to handle interaction events.
 * Use the {@link Fragment_EDTab_Fight#newInstance} factory method to
 * create an instance of this fragment.
 */
public class Fragment_EDTab_Fight extends Fragment implements View.OnClickListener{

    private static final String TAG = Fragment_EDTab_Fight.class.getSimpleName();
    private static String hostIP = null;
    private static int hostPort = 0;
    NetworkClient client = null;

    @Override public void onResume()
    {
        super.onResume();
        Log.d(TAG, "on Resume");
    }

    @Override
    public void onDestroy()
    {
        super.onDestroy();
        client.disconnect();
    }

    @Override public void onActivityCreated(@Nullable Bundle savedInstanceState)
    {
        super.onActivityCreated(savedInstanceState);

        StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
        StrictMode.setThreadPolicy(policy);

        Button button_chaff = (Button) getActivity().findViewById(R.id.button_chaff);
        Button button_heat = (Button) getActivity().findViewById(R.id.button_heat);
        Button button_lastWaypoint = (Button)getActivity().findViewById(R.id.button_lastWaypoint);
        Button button_highWake = (Button)getActivity().findViewById(R.id.button_highWake);
        Button button_lowWake = (Button)getActivity().findViewById(R.id.button_lowWake);
        Button button_pref = (Button)getActivity().findViewById(R.id.button_pref);

        button_chaff.setOnClickListener(this);
        button_heat.setOnClickListener(this);
        button_lastWaypoint.setOnClickListener(this);
        button_highWake.setOnClickListener(this);
        button_lowWake.setOnClickListener(this);
        button_pref.setOnClickListener(this);

        SharedPreferences prefs = PreferenceManager.getDefaultSharedPreferences(getActivity());
        hostIP = prefs.getString("host_addr","");
        String hostPortString = prefs.getString("host_port","");
        if (!hostPortString.isEmpty()) hostPort = Integer.parseInt(hostPortString);
        client = new NetworkClient(hostIP, hostPort);
        //boolean success = client.connect();
        //Log.d(TAG, String.valueOf(success));
        //success = client.sendKeyoverNetwork(NetworkMessage.CHAFF);
        //Log.d(TAG, String.valueOf(success));

    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_edtab_fight, container, false);

    }

    @Override    public void onClick(View view)
    {
    int buttonId = view.getId();
    switch (buttonId)
        {
        case R.id.button_chaff: if(!client.sendKeyOverNetwork(NetworkMessage.CHAFF))displayConnectionError() ;
            break;
        case R.id.button_heat: if(!client.sendKeyOverNetwork(NetworkMessage.HEAT))displayConnectionError();
            break;
        case R.id.button_lastWaypoint: if(!client.sendKeyOverNetwork(NetworkMessage.LASTWAY))displayConnectionError();
            break;
        case R.id.button_highWake: if(!client.sendKeyOverNetwork(NetworkMessage.HIGHWAKE))displayConnectionError();
            break;
        case R.id.button_lowWake: if(!client.sendKeyOverNetwork(NetworkMessage.LOWWAKE))displayConnectionError();
            break;
        case R.id.button_pref: Intent intent = new Intent(getActivity(), AppPreferences.class);
            startActivity(intent);
            break;
        }
    }

    private void displayConnectionError()
    {

        new AlertDialog.Builder(getActivity())
                .setTitle(R.string.stringConnectionErrorHead)
                .setMessage(R.string.stringConnectionErrorText)
                .setIcon(android.R.drawable.ic_dialog_alert)
                .setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener()
                    {
                    public void onClick(DialogInterface dialog, int which)
                        {

                        }
                    }).show();
    }

}

