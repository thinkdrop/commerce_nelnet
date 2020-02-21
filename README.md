# ASU Commerce
## Nelnet QuikPAY

### Description
This module allows you to configure an ASU Nelnet QuikPAY payment method for Drupal Commerce. Due to licensing restrictions, this module is only available by special request. Email webconsulting@asu.edu with details about your project.

### Installation
Install the module as [any other Drupal module](http://drupal.org/node/70151).

Dependencies (subject to change): **rules**, **commerce**, **defaultconfig**, **telephone**, **features**. If available, it is helpful to enable the accompanying 'UI' submodules for the dependencies listed (such as Rules UI).

Once you've installed the QuikPAY module, configure it within the Commerce store configuration menus:
* Administration > Store > Configuration > Payment Methods

**Choose a redirect method:**
* RTPN Mode
	* **Description:** When a customer clicks on the "proceed to payment" link, QuikPAY opens in a separate window. Once payment is complete, the customer must close that window. QuikPAY will asyncronously notify your Drupal site that a payment has been made, by sending a request to your RTPN page (/quikpay/rtpn). This request is subject to authentication via the keys setup in the payment method configuration, and obtained via ASU Financial Services' Nelnet liaison (more on this below). When the payment completes, the checkout pane will still be open on the Drupal site, but the cart should be cleared. This is a limitation imposed by the QuikPAY RTPN interface.
	* **Note:** Real Time Payment Notifications (RTPN) will need to hit http://yourdomain/quikpay/rtpn (or if you are using SSL, https://yourdomain/quikpay/rtpn) in order to notify your site that a payment has completed. Keep in mind, if using SSL, that self-signed, expired and misconfigured SSL certificates will result in RTPN notifications failing to complete.
* Redirect URL mode (preferred)
	* **Description:** With this mode enabled, when you proceed to the QuikPAY payment site, it does not open in a new window, and when payment completes, you are redirected back to your Drupal site.
	* **Note:** Ask your ASU Financial Services Nelnet liaison to configure the redirectUrl parameter to be the same path you'd have used as the RTPN (the default is https://yourdomain/quikpay/rtpn).

**To determine which modes are available to you and to obtain the proper testing and production servers, please speak with the ASU Financial Services Nelnet liaison.**

The "proceed to checkout" link includes a time-sensitive hash. This means the link will time out. Quikpay only honors hashes with times within 5 minutes of the Quikpay server. This means:
* You want to make sure your server's time is relatively close to your timezone as reported at http://tycho.usno.navy.mil/
* The "proceed to checkout" link times out for users after 5 minutes, give or take. When the user clicks the expired link, QuikPAY will report an error. The user can close that window/tab and return to the original page with the link and refresh the page to get a valid link.

Once your test site is working, request that the production QuikPAY payment processing site be set up and get the keys for it from the ASU Financial Services Nelnet liaison. Please allow 10 days for processing of the final production setup. Enter the production keys and production QuikPAY URL into the QuikPAY payment method settings, and switch to production mode when ready.

**Support for multiple order types**

The QuikPAY module supports multiple Nelnet Quikpay order types. To implement:
1. Setup accounts for each order type with Financial Services, each with a unique order type name string. All accounts should implement identical keys, however, as they will use the same payment method in Drupal as the base-config.
2. Choose one order type to serve as the default fallback order type. Set that as the order type value in the QuikPAY payment method configs.
3. A Drupal taxonomy vocabulary (quikpay_order_type) was created when the module was enabled. Add all order types as taxonomy terms (see the example order type term available in the vocabulary). Use the order type name strings configured with Nelnet as the term names (CAPs count).
4. Add a taxonomy term reference field to all products you'd like to be able to reference custom order types (other than the default). Use the machine name field_quikpay_order_type. And be sure to hide the field in the display settings.
5. A rule in the Rules UI was created when the module was enabled that empties the shopping cart in the event that a new item is added. Make sure to keep this enabled, as this prevents accumulation of multiple products pointing to differing order types.

### Permissions
Inherited from Commerce. Anonymous will need "access checkout" permission in order to access the RTPN page.

### Pages
* Admin UI for Configuring Payment Method, accessed through store settings:
```/admin/commerce/config/payment-methods/manage/commerce_payment_quikpay/ ```
* Page used by QuikPAY to report payments:
```/quikpay/rtpn ```

### Hooks
A hook is available to alter hash parameters, but this shouldn't be needed in most cases:
```hook_quikpay_hash_param_alter(&$variables, &$param, $order)```

### Credits
The QuikPAY module was created by:
* Michael Samuelson (<mlsamuel@asu.edu> / <mlsamuelson@gmail.com> / http://mlsamuelson.com)
* Zohair Zaidi (<zohair.zaidi@asu.edu> / <zohair.zaidi@gmail.com>)

Additional module development completed by:
* Bryan Roseberry (<aubjr@asu.edu>)
* Michael Gilardi (<mgilardi@asu.edu>)
