$.preloadImages = function(){
   for(var i = 0; i<arguments.length; i++){
      $("<img />").attr("src", arguments[i]);
   }
}
 
$(document).ready(function(){
   $.preloadImages(
	"/images/structure/traffic/center_01_hover.gif",
	"/images/structure/traffic/center_02_hover.gif",
	"/images/structure/traffic/center_03_hover.gif",
	"/images/structure/traffic/traffic_01_hover.gif",
	"/images/structure/traffic/traffic_02_hover.gif",
	"/images/structure/traffic/traffic_03_hover.gif",
	"/images/structure/traffic/traffic_04_hover.gif",
	"/images/structure/traffic/traffic_05_hover.gif",
	"/images/structure/traffic/traffic_06_hover.gif",
	"/images/structure/traffic/traffic_07_hover.gif",
	"/images/structure/traffic/traffic_08_hover.gif",
	"/images/structure/traffic/traffic_09_hover.gif",
	"/images/structure/traffic/traffic_10_hover.gif",
	
	"/images/structure/radio/center_01_hover.gif",
	"/images/structure/radio/radio_01_hover.gif",
	"/images/structure/radio/radio_02_hover.gif",
	"/images/structure/radio/radio_03_hover.gif",
	"/images/structure/radio/radio_04_hover.gif",
	"/images/structure/radio/radio_05_hover.gif",
	"/images/structure/radio/radio_06_hover.gif",
	
	"/images/structure/outpost/outpost_01_hover.gif",
	"/images/structure/outpost/outpost_02_hover.gif",
	"/images/structure/outpost/outpost_03_hover.gif",
	"/images/structure/outpost/outpost_04_hover.gif",
	"/images/structure/outpost/outpost_05_hover.gif",
	"/images/structure/outpost/outpost_06_hover.gif",
	"/images/structure/outpost/outpost_07_hover.gif",
	"/images/structure/outpost/outpost_08_hover.gif",
	"/images/structure/outpost/outpost_09_hover.gif",
	"/images/structure/outpost/outpost_10_hover.gif"
   );
});