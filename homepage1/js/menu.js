jQuery(document).ready(function(){
var fl;
var fl2;
if ($.browser.msie && $.browser.version < 8)
{
	var oldIE 	=	true;			// Checking if it's IE6 or IE7
}

//	Adding 'active' class to menu items (hover effect)
    jQuery('div.top-menu ul.menu li').hover(
        function(){		// MouseOVER
            fl = jQuery(this).hasClass('active');
            if(!fl)
            {
				jQuery(this).addClass("active");
            }
        },
        function(){		// MouseOUT
            if(!fl)
            {
				jQuery(this).removeClass("active");
            }
        }   
    );

//	Adding drop-down functionality
    jQuery('div.top-menu ul.menu li.parent').hover(
    function(){		// MouseOVER
        fl2	= jQuery(this).hasClass('active');
        if (!fl2)
        {
			jQuery(this).addClass("active");
        }
		
		if (!oldIE)								
		{
			jQuery(this).find('ul').fadeIn('fast');
		}
        jQuery(this).find('ul').show();
		
		if (oldIE)								
        {
            jQuery(this).find('ul').css('margin-left','-50px')	// IE 6,7 Fix
        }
    },

    function(){		// MouseOUT
        if(!fl2)
        {
            jQuery(this).removeClass("active");  
        }
		if (!oldIE)
		{
			jQuery(this).find('ul').fadeOut('fast');
		}
		else 
		{
			jQuery('div.top-menu ul.menu li.parent ul').hide();		// IE 6,7 Fix
		}
    }
    ); 
	
//	Adding hover effect to menu sub-items
	jQuery('div.top-menu ul.menu li.parent ul li').hover(
	function(){		// MouseOVER
		jQuery(this).css({backgroundColor:'#ff5b03'});
	},
	function(){		// MouseOUT
		jQuery(this).css('background-color','#DC4B05');
	}
	);
});