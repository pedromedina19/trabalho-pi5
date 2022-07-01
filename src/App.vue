<template>
	<div id="app">
		<SensorProject />
	</div>
</template>

<script>
import SensorProject from './components/SensorProject.vue';

export default {
	name: 'App',
	components: {
		SensorProject,
	},
};
</script>

<style>
@import url('https://fonts.googleapis.com/css2?family=Open+Sans&display=swap');



#menu-h{
    background-color: rgb(37, 37, 39);
}

#menu-h ul {
    max-width: 800px;
    list-style: none;
    padding: 0;
}

#menu-h ul li {
    display: inline;
}

#menu-h ul li a {
    color: #FFF;
    padding: 2px;
    display: inline-block;
    text-decoration: none;
    transition: background .4s;
}

#menu-h ul li a:hover {
    background-color: rgb(24, 139, 233);
}

header{
    background-color: #2E2E2E;
    color: white;
    padding: 4px;
    margin-bottom: 40px;
}
#principal{
  margin: auto;
  width: 80%;
}
#coluna1{
  width: 60%;
  text-align: justify;
}

#coluna2{
  width: 40%;
  text-align: center;
}

#app {
	font-family: Avenir, Helvetica, Arial, sans-serif;
	-webkit-font-smoothing: antialiased;
	-moz-osx-font-smoothing: grayscale;
	text-align: center;
	color: #EFF5FB;
	margin-top: 60px;
}
</style>
