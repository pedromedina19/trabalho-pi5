import firebase from '../firebase';

const databaseTemperature = firebase.ref('/dht22/temperatura');
const databaseHumidade = firebase.ref('/dht22/humidade');

export default {
	getAllTemperature() {
		return databaseTemperature;
	},
	getAllHumidade() {
		return databaseHumidade;
	},
};
