package edu.vt.a4754_final_ryans6;

import android.os.AsyncTask;
import android.util.Log;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

/**
 * Handles all API requests to our REST API
 */
public class BackgroundAPIHandler extends AsyncTask<String, Void, String> {

    private String mRequestURI = "";

    /**
     * Builds a new BackgroundAPIHandler
     *
     * @param endURI          The last part of the URI after REST/
     */
    public BackgroundAPIHandler(String endURI) {

        mRequestURI = endURI;

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

        String urlString = mRequestURI; // URL to call

            InputStream in = null;
            StringBuffer sb = new StringBuffer();
            try {

                URL url = new URL(urlString);

                HttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();

                in = new BufferedInputStream(urlConnection.getInputStream());
                BufferedReader br = new BufferedReader(new InputStreamReader(in));
                String inputLine = "";
                while ((inputLine = br.readLine()) != null) {
                    sb.append(inputLine);
                }
                result = sb.toString();


                if (urlConnection.getResponseCode() == 200) {//HttpURLConnection.HTTP_OK) {
                    Log.i("Test", "200 okay");

                } else {
                    // Server returned HTTP error code.
                    Log.i("Test", urlConnection.getResponseCode() + " bad");
                }
            } catch (MalformedURLException e) {
                Log.i("Test", e.toString());
            } catch (IOException e) {
                Log.i("Test", e.toString());
            }


        return result;
    }


    @Override
    protected void onPostExecute(String result) {
    }
}