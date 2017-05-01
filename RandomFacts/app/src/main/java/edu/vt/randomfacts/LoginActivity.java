package edu.vt.randomfacts;

import android.app.AlarmManager;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.SystemClock;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.Calendar;
import java.util.concurrent.ExecutionException;

public class LoginActivity extends AppCompatActivity {
    private Button signInButton;
    private Button createAccountButton;
    private EditText usernameEditText;
    private EditText passwordEditText;

    private SharedPreferences mPrefs;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        signInButton = (Button) findViewById(R.id.signInButton);
        createAccountButton = (Button) findViewById(R.id.createAccountButton);
        usernameEditText = (EditText) findViewById(R.id.usernameEditText);
        passwordEditText = (EditText) findViewById(R.id.passwordEditText);

        signInButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                signIn();
            }
        });

        createAccountButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                createAccount();
            }
        });

        AlarmManager mgr = (AlarmManager) this.getSystemService(Context.ALARM_SERVICE);
        mPrefs = this.getSharedPreferences("vt.edu.RandomFacts", Context.MODE_PRIVATE);
//        Intent intent = new Intent(this, PushActivity.class);
//        PendingIntent pi = PendingIntent.getActivity(this, 0, intent, 0);
//        pi = PendingIntent.getBroadcast(this, 0, intent, 0);
        Thread t = new Thread(new Runnable() {
            public void run() {
                while(true) {
                   pushNot();
                }
            }
        });

        t.start();
        checkForValidToken();
    }

    private void signIn() {
        String credsToSend = usernameEditText.getText().toString() + ":" + passwordEditText.getText().toString();
        String response = "";
        String status = "";
        String token = "";

        try {
            response = new BackgroundAPIHandler("/facts/accounts", "GET").execute(credsToSend).get();
            Log.i("YO", response);
            JSONObject obj = new JSONObject(response);
            status = obj.getString("Status");
            token = obj.getString("Token");

        } catch (InterruptedException e) {
            e.printStackTrace();
        } catch (ExecutionException e) {
            e.printStackTrace();
        } catch (JSONException e) {
            e.printStackTrace();
        }

        if(token.equals("N/A")) { //Failure of some sort
            Toast.makeText(this, status,
                    Toast.LENGTH_LONG).show();
        } else {
            Toast.makeText(this, status + ". Logging you in",
                    Toast.LENGTH_LONG).show();

            SharedPreferences.Editor editor = mPrefs.edit();
            editor.putString("vt.edu.RandomFacts.username", usernameEditText.getText().toString());
            editor.putString("vt.edu.RandomFacts.token", token);
            editor.commit();

            //switch to new activity
            Intent factIntent = new Intent(this, FactActivity.class);
            startActivity(factIntent);
        }
    }

    private void createAccount() {
        String credsToSend = usernameEditText.getText().toString() + ":" + passwordEditText.getText().toString();
        String response = "";
        String status = "";
        String token = "";

        try {
            response = new BackgroundAPIHandler("/facts/accounts", "POST").execute(credsToSend).get();
            Log.i("YO", response);
            JSONObject obj = new JSONObject(response);
            status = obj.getString("Status");
            token = obj.getString("Token");

        } catch (InterruptedException e) {
            e.printStackTrace();
        } catch (ExecutionException e) {
            e.printStackTrace();
        } catch (JSONException e) {
            e.printStackTrace();
        }

        if(token.equals("N/A")) { //Failure of some sort
            Toast.makeText(this, status,
                    Toast.LENGTH_LONG).show();
        } else {
                Toast.makeText(this, status + ". Logging you in",
                        Toast.LENGTH_LONG).show();

            SharedPreferences.Editor editor = mPrefs.edit();
            editor.putString("vt.edu.RandomFacts.username", usernameEditText.getText().toString());
            editor.putString("vt.edu.RandomFacts.token", token);
            editor.commit();

            //switch to new activity
            Intent factIntent = new Intent(this, FactActivity.class);
            startActivity(factIntent);
        }
    }

    private void checkForValidToken() {
        //send get with token
        if(!mPrefs.getString("vt.edu.RandomFacts.token", "").equals("")) { //if user has already made a token
            //send get with token to check if valid
            //if(valid)
                //initiate intent for factActivity
            //else
                //make user log in
        }
        //Otherwise no account has ever been made. make them make an account
    }

    private void pushNot(){
        Intent intent = new Intent(this, FactActivity.class);
        PendingIntent pIntent = PendingIntent.getActivity(this, 0, intent, 0);
        AlarmManager mgr = (AlarmManager) this.getSystemService(this.ALARM_SERVICE);
        PendingIntent pi = PendingIntent.getService(this, 0, intent, 0);
        Calendar calendar = Calendar.getInstance();
//        calendar.setTimeInMillis(System.currentTimeMillis());
//        calendar.set(Calendar.HOUR_OF_DAY, 12);

// With setInexactRepeating(), you have to use one of the AlarmManager interval
// constants--in this case, AlarmManager.INTERVAL_DAY.
        //mgr.setInexactRepeating(AlarmManager.RTC_WAKEUP, calendar.getTimeInMillis(),
                //AlarmManager.INTERVAL_DAY, pi);

//        mgr.setInexactRepeating(AlarmManager.ELAPSED_REALTIME_WAKEUP,
//                SystemClock.elapsedRealtime() + 1000,
//                1000, pIntent);

// build notification
// the addAction re-use the same intent to keep the example short
        Notification n  = new Notification.Builder(this)
                .setContentTitle("Time for your Fact of the day")
                .setContentText("Click me!")
                .setSmallIcon(R.mipmap.ic_launcher)
                .setContentIntent(pIntent)
                .setAutoCancel(true)
                .build();
        int t = (int)calendar.get(calendar.MINUTE);
        StringBuilder t_str = new StringBuilder();
        t_str.append(t);
        String str_t = t_str.toString();
        //Log.d("Message", str_t);
        if(t == 30) {
            //Log.d("Message", "In If");
            NotificationManager notificationManager =
                    (NotificationManager) getSystemService(NOTIFICATION_SERVICE);

            notificationManager.notify(0, n);
        }
    }
}
