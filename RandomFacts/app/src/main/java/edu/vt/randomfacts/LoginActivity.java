package edu.vt.randomfacts;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
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

        mPrefs = this.getSharedPreferences("vt.edu.RandomFacts", Context.MODE_PRIVATE);

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
}
