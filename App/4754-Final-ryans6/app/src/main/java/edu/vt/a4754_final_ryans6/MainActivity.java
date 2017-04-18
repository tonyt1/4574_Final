package edu.vt.a4754_final_ryans6;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutionException;

/*import io.appflate.restmock.RESTMockServer;
import io.appflate.restmock.RESTMockServerStarter;
import io.appflate.restmock.android.AndroidAssetsFileParser;
import io.appflate.restmock.android.AndroidLogger;*/

//import static io.appflate.restmock.utils.RequestMatchers.pathContains;

public class MainActivity extends AppCompatActivity {

    private Button but;
    private TextView text;
    private List<String> values;
    private int factCounter;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
       /* RESTMockServerStarter.startSync(new AndroidAssetsFileParser(this),new AndroidLogger());
        RESTMockServer.whenGET(pathContains("h")).thenReturnString(200, "{lllll}");*/

        factCounter = 0;

        //Create values array for testing
        values = new ArrayList<String>();
        values.add("Fact1");
        values.add("Fact2");
        values.add("Fact3");
        values.add("Fact4");
        values.add("Fact5");
        values.add("Fact6");
        values.add("Fact7");
        values.add("Fact8");
        values.add("Fact9");
        values.add("Fact10");
        values.add("Fact11");
        values.add("Fact12");

        but = (Button) findViewById(R.id.button);
        text = (TextView) findViewById(R.id.text);

        //Create listener for the button
        but.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                getRandomFact();
            }
        });

    }

    private void getRandomFact() {
        String randomFactJSON;

        if(factCounter == 12)
            factCounter = 0;

        try {
            //randomFact = new BackgroundAPIHandler(RESTMockServer.getUrl()).execute().get();

            //http://echo.jsontest.com/funFact/ URL allows for dynamic creation of JSON objects. I create a simple JSON object
            //that contains the key "funfact" and a value based off of a counter. This mimics multiple GET requests to our server
            //for random facts, without actually having the server running
            randomFactJSON = new BackgroundAPIHandler("http://echo.jsontest.com/funFact/" + values.get(factCounter)).execute().get();
            factCounter++;

            //parse json object
            JSONObject obj = new JSONObject(randomFactJSON);
            String fact = obj.getString("funFact");

            //set text to the fun fact
            text.setText(fact);

            //Log.i("BBBBBB", obj.toString());
            //Log.i("BBBBBB", randomFact);


        } catch (InterruptedException | ExecutionException  | JSONException e) {
            e.printStackTrace();
        }
    }
}
