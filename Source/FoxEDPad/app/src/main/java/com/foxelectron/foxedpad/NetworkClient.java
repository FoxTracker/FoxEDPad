package com.foxelectron.foxedpad; /**
 * Created by Adrian on 27.11.2016.
 */
import android.os.AsyncTask;

import java.net.*;
import java.io.*;
import android.util.Log;

public class NetworkClient //TODO implement Async Task
{


    private static String host = null;
    private static int port = 0;
    private static Socket client = null;
    private static DataOutputStream outToServer= null;

    public  NetworkClient(String _host, int _port)
        {
        this.host = _host;
        this.port = _port;
        }


public boolean connect()
    {
    try
        {
        client = new Socket(host, port);
        outToServer = new DataOutputStream(client.getOutputStream());
        }
    catch (IOException e) {   e.printStackTrace(); return false; }

    return true;
    }

public void disconnect()
    {
    if (client == null ) return;
    if (client.isConnected())
         try
            {
            client.close();
            }
         catch (IOException e) { e.printStackTrace();  }

     client = null;
    }



public boolean sendKeyOverNetwork(int i)
    {
        boolean connectionSuccess = false;
        if (client == null) connectionSuccess = connect();
        //if(!connectionSuccess) Log.d("!", "connectionSuccess = false");//return false;
        if (!client.isConnected()) return false;

        try
            {
            outToServer.writeBytes(NetworkMessage.APPLICATION_NETWORK_CONSTANT + i + '\n');
            outToServer.flush();
            }
        catch (IOException e) { e.printStackTrace(); return false; }

        return true;
    }



//
//    @Override protected Object doInBackground(Object[] objects)
//    {
//        return null;
//    }
}

