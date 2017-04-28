package edu.vt.randomfacts;

import android.content.Context;
import android.content.SharedPreferences;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import org.json.JSONException;
import org.json.JSONObject;
import org.w3c.dom.Text;

import java.util.concurrent.ExecutionException;

public class FactActivity extends AppCompatActivity {

    private Button randomButton;
    private Button topicButton;
    private EditText topicEditText;
    private TextView factTextView;

    private SharedPreferences mPrefs;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_fact);

        randomButton = (Button) findViewById(R.id.randomButton);
        topicButton = (Button) findViewById(R.id.topicButton);
        topicEditText = (EditText) findViewById(R.id.topicEditText);
        factTextView = (TextView) findViewById(R.id.factTextView);

        randomButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                getRandomFact();
            }
        });

        topicButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                getTopicBasedFact();
            }
        });

        mPrefs = this.getSharedPreferences("vt.edu.RandomFacts", Context.MODE_PRIVATE);
    }

    private void getRandomFact() {
        String uName = mPrefs.getString("vt.edu.RandomFacts.username", "");
        String token = mPrefs.getString("vt.edu.RandomFacts.token", "");
        String credsToSend = uName + ":" + token;
        String response = "";
        String facts = "";

        try {
            response = new BackgroundAPIHandler("/facts/api/random", "GET").execute(credsToSend).get();
            Log.i("YO", response);
            JSONObject obj = new JSONObject(response);
            facts = obj.getString("facts");

        } catch (InterruptedException e) {
            e.printStackTrace();
        } catch (ExecutionException e) {
            e.printStackTrace();
        } catch (JSONException e) {
            e.printStackTrace();
        }
        factTextView.setText(facts);
    }

    private void getTopicBasedFact() {
        if(topicEditText.getText().toString().equals("")) {
            Toast.makeText(this, "Please enter a topic above",
                    Toast.LENGTH_LONG).show();
        } else {
            String uName = mPrefs.getString("vt.edu.RandomFacts.username", "");
            String token = mPrefs.getString("vt.edu.RandomFacts.token", "");
            String credsToSend = uName + ":" + token;
            String response = "";
            String facts = "";

            String[] splitTopic = topicEditText.getText().toString().split("\\s+");
            String params = "";
            for(int i = 0; i < splitTopic.length - 1; i++) {//Go until second to last one and add '+' in between
                params += splitTopic[i] + "+";
            }
            params += splitTopic[splitTopic.length - 1];//add in last one

            try {
                response = new BackgroundAPIHandler("/facts/api/subject?topic=" + params, "GET").execute(credsToSend).get();
                Log.i("YO", response);
                JSONObject obj = new JSONObject(response);
                facts = obj.getString("facts");

            } catch (InterruptedException e) {
                e.printStackTrace();
            } catch (ExecutionException e) {
                e.printStackTrace();
            } catch (JSONException e) {
                e.printStackTrace();
            }
            factTextView.setText(facts);
        }
    }
}
