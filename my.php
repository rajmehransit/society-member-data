
<?php
// Form submission script
include_once 'Submit.php';
?>
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <title>contect form project</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width,initial-scale=1">

    <link rel="stylesheet" href="style.css">
  </head>
  <body class="box">
    
    <div class="contactFrm">
     <div class="tital">CONTECT FORM</div>
      <!-- Status message -->
      <?php if(!empty($statusMsg)){ ?>
          <div class="status-msg <?php echo $status; ?>"><?php echo $statusMsg; ?></div>
      <?php } ?>

      <!-- Form fields -->
      <form action="" method="post">
          <div class="form-input">
              <label for="name">Name</label>
              <input type="text" name="name" placeholder="Enter your name" class="form control" value="<?php echo !empty($postData['name'])?$postData['name']:''; ?>" required="">
          </div>
          <div class="form-input">
              <label for="email">Email</label>
              <input type="email" name="email" placeholder="Enter your email" class="form control" value="<?php echo !empty($postData['email'])?$postData['email']:''; ?>" required="">
          </div>
          <div class="form-input">
              <label for="name">password</label>
              <input type="password" name="password" placeholder="Enter your password" class="form control" value="<?php echo !empty($postData['password'])?$postData['password']:''; ?>" required="">
          </div>
          <div class="form-input">
              <label for="subject">Subject</label>
              <input type="text" name="subject" placeholder="Enter subject" value="<?php echo !empty($postData['subject'])?$postData['subject']:''; ?>" required="">
          </div>
          <div class="form-input">
              <label for="message">Message</label>
              <textarea name="message" placeholder="Type your message here" required=""><?php echo !empty($postData['message'])?$postData['message']:''; ?></textarea>
          </div>

          <input type="submit" name="submit" class="btn" value="submit">
      </form>

    </div>
  </body>
</html>
