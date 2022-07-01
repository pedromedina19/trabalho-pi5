import firebase from 'firebase/app';
import 'firebase/database';

const firebaseConfig = {
	apiKey: "AIzaSyD-DZfCyTXZ0uNKcg2mYaR_OaCLwlyo_6E",
    authDomain: "esp8266-dht22-d73de.firebaseapp.com",
    databaseURL: "https://esp8266-dht22-d73de-default-rtdb.firebaseio.com",
    projectId: "esp8266-dht22-d73de",
    storageBucket: "esp8266-dht22-d73de.appspot.com",
    messagingSenderId: "223173696077",
    appId: "1:223173696077:web:7a740dc85d80cce5511a04",
    measurementId: "G-6T6R5QPXH5"
};

firebase.initializeApp(firebaseConfig);

export default firebase.database();
