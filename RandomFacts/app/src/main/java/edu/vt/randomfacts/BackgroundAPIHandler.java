package edu.vt.randomfacts;

import android.os.AsyncTask;
import android.util.Base64;
import android.util.Log;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

/**
 * Handles all API requests to our REST API
 */
public class BackgroundAPIHandler extends AsyncTask<String, Void, String> {

    private String mRequestURI = "";
    private String mHTTPRequestType = "";

    /**
     * Builds a new BackgroundAPIHandler
     *
     * @param endURI          The last part of the URI after REST/
     */
    public BackgroundAPIHandler(String endURI, String requestType) {

        mRequestURI = endURI;
        mHTTPRequestType = requestType;

    }

    @Override
    protected void onPreExecute() {
        super.onPreExecute();
    }


    /**
     * Sends out the HTTP request to the REST API
     *
     * @param params Any params that are to be sent with the request
     * @return The response data for GET requests, null for POST requests
     */
    @Override
    protected String doInBackground(String... params) {

        String result = null;

        String urlString = "http://ec2-54-191-23-45.us-west-2.compute.amazonaws.com:8000" + mRequestURI; // URL to call

        if (mHTTPRequestType.equals("POST")) {

            try {

                URL url = new URL(urlString);
                HttpURLConnection urlConnection = (HttpURLConnection)url.openConnection();

                String userCredentials = params[0]; //params[0] == username:password

                byte[] data = userCredentials.getBytes("UTF-8");

                String basicAuth = "Basic " + new String(Base64.encodeToString(data, Base64.DEFAULT));
                urlConnection.setRequestProperty ("Authorization", basicAuth);
                urlConnection.setRequestMethod("POST");
                urlConnection.setRequestProperty("Content-Type", "application/json;charset=utf8");
                urlConnection.setRequestProperty("Accept", "application/json");
                urlConnection.setRequestProperty("Method", "POST");
                urlConnection.setUseCaches(false);
                urlConnection.setDoInput(true);
                urlConnection.setDoOutput(true);

                InputStream in = null;
                StringBuffer sb = new StringBuffer();

                in = new BufferedInputStream(urlConnection.getInputStream());
                BufferedReader br = new BufferedReader(new InputStreamReader(in));
                String inputLine = "";
                while ((inputLine = br.readLine()) != null) {
                    sb.append(inputLine);
                }
                result = sb.toString();

                if (urlConnection.getResponseCode() == 200) {//HttpURLConnection.HTTP_OK) {
                    Log.i("YO", "good");

                } else {
                    // Server returned HTTP error code.
                    Log.i("YO", "" + urlConnection.getResponseCode() + " " + params[0]);
                }
            } catch (MalformedURLException e) {
                Log.i("YO", e.toString());
            } catch (IOException e) {
                Log.i("YO", e.toString());
            }














/*
                URL url = new URL(urlString);

                HttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();

                urlConnection.setDoOutput(true);
                urlConnection.setRequestMethod("POST");

                urlConnection.setRequestProperty("Content-Type", "application/json;charset=utf8");
                urlConnection.setRequestProperty("Accept", "application/json");
                urlConnection.setRequestProperty("Method", "POST");

                OutputStreamWriter writer = new OutputStreamWriter(
                        urlConnection.getOutputStream());

                writer.write(params[0]);
                writer.close();

                if (urlConnection.getResponseCode() == 200) {//HttpURLConnection.HTTP_OK) {
                    Log.i("YO", "good");

                } else {
                    // Server returned HTTP error code.
                    Log.i("YO", "" + urlConnection.getResponseCode() + " " + params[0]);
                }
            } catch (MalformedURLException e) {
                Log.i("YO", e.toString());
            } catch (IOException e) {
                Log.i("YO", e.toString());
            }
            */
        } else if (mHTTPRequestType.equals("GET")) {

            InputStream in = null;
            StringBuffer sb = new StringBuffer();
            try {

                URL url = new URL(urlString);

                HttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();

                String userCredentials = params[0]; //params[0] == username:password

                byte[] data = userCredentials.getBytes("UTF-8");

                String basicAuth = "Basic " + new String(Base64.encodeToString(data, Base64.DEFAULT));
                urlConnection.setRequestProperty ("Authorization", basicAuth);

                in = new BufferedInputStream(urlConnection.getInputStream());
                BufferedReader br = new BufferedReader(new InputStreamReader(in));
                String inputLine = "";
                while ((inputLine = br.readLine()) != null) {
                    sb.append(inputLine);
                }
                result = sb.toString();


                if (urlConnection.getResponseCode() == 200) {//HttpURLConnection.HTTP_OK) {
                    Log.i("YO", "good");

                } else {
                    // Server returned HTTP error code.
                    Log.i("YO", "" + urlConnection.getResponseCode());
                }
            } catch (MalformedURLException e) {
                Log.i("YO", e.toString());
            } catch (IOException e) {
                Log.i("YO", e.toString());
            }

        } //else if

        return result;
    }


    @Override
    protected void onPostExecute(String result) {
    }
}