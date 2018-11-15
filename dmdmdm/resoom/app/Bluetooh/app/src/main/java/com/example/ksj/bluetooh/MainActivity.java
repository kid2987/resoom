package com.example.ksj.bluetooh;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.content.Intent;
import android.support.v4.view.ViewPager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import app.akexorcist.bluetotohspp.library.BluetoothSPP;
import app.akexorcist.bluetotohspp.library.BluetoothState;
import app.akexorcist.bluetotohspp.library.DeviceList;

public class MainActivity extends AppCompatActivity {

    private BluetoothSPP bt;
    TextView showBt;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        bt=new BluetoothSPP(this);

        showBt=findViewById(R.id.please);

        if(!bt.isBluetoothAvailable()){//블루투스 사용불가
            Toast.makeText(getApplicationContext(),"블루투스가 꺼져있습니다.",
                    Toast.LENGTH_SHORT).show();
            finish();
        }

        bt.setOnDataReceivedListener(new BluetoothSPP.OnDataReceivedListener() {//데이터 수신
            @Override
            public void onDataReceived(byte[] data, String message) {
                showBt.setText(message);
            }
        });

        bt.setBluetoothConnectionListener(new BluetoothSPP.BluetoothConnectionListener() {//연결
            @Override
            public void onDeviceConnected(String name, String address) {
                Toast.makeText(getApplicationContext(),"Connected to"+name+"\n"
                +address,Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onDeviceDisconnected() {//연결해제
                Toast.makeText(getApplicationContext(),"Connection lost",
                        Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onDeviceConnectionFailed() {//연결실패
                Toast.makeText(getApplicationContext(),"Unable to connect",
                        Toast.LENGTH_SHORT).show();
            }
        });

        Button btnConnect=findViewById(R.id.btnConnect);//연결시도
        btnConnect.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                if(bt.getServiceState()==BluetoothState.STATE_CONNECTED){
                    bt.disconnect();
                }
                else{
                    Intent intent=new Intent(getApplicationContext(),DeviceList.class);
                    startActivityForResult(intent,BluetoothState.REQUEST_CONNECT_DEVICE);
                }
            }
        });
    }

    public void onDestroy(){
        super.onDestroy();
        bt.stopService();
    }

    public void onStart(){
        super.onStart();
        if(!bt.isBluetoothEnabled()){
            Intent intent=new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(intent,BluetoothState.REQUEST_ENABLE_BT);
        }
        else{
            if(!bt.isServiceAvailable()){
                bt.setupService();
                bt.startService(BluetoothState.DEVICE_OTHER);//안드로이드가 아닌 디바이스와 연결
                setup();
            }
        }
    }

    public void onActivityResult(int requestCode, int resultCode, Intent data){
        if(requestCode==BluetoothState.REQUEST_CONNECT_DEVICE){
            if (resultCode==Activity.RESULT_OK)
                bt.connect(data);
        }
        else if(requestCode==BluetoothState.REQUEST_ENABLE_BT){
            if(resultCode==Activity.RESULT_OK){
                bt.setupService();
                bt.startService(BluetoothState.DEVICE_OTHER);
                setup();
            }
            else{
                Toast.makeText(getApplicationContext(), "Bluetooth was not enable",
                        Toast.LENGTH_SHORT).show();
                finish();
            }
        }
    }

    public void setup(){
        final Button btnOn=findViewById(R.id.btnOn);//아두이노에 데이터 전송하는 코드
        final Button btnOff=findViewById(R.id.btnOff);
        btnOff.setVisibility(View.INVISIBLE);
        btnOn.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                bt.send("On",true);
                btnOn.setVisibility(View.INVISIBLE);
                btnOff.setVisibility(View.VISIBLE);
            }
        });

        btnOff.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v){
                bt.send("Off",true);
                btnOn.setVisibility(View.VISIBLE);
                btnOff.setVisibility(View.INVISIBLE);
            }
        });
    }
}