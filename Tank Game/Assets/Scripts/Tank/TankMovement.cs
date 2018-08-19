using UnityEngine;

public class TankMovement : MonoBehaviour
{
    public int m_PlayerNumber = 1;
    public float m_Speed = 12f;             
    public float m_TurnSpeed = 180f;       
    public AudioSource m_MovementAudio;    
    public AudioClip m_EngineIdling;       
    public AudioClip m_EngineDriving;      
    public float m_PitchRange = 0.2f;

    // m underscore means it belongs to the class and is a member variable.  It can be used anywhere ie is not local to a function.
    private string m_MovementAxisName;     
    private string m_TurnAxisName;         
    private Rigidbody m_Rigidbody;         
    private float m_MovementInputValue;    
    private float m_TurnInputValue;        
    private float m_OriginalPitch;


    private void Awake()
    {
        m_Rigidbody = GetComponent<Rigidbody>();
    }

    // called after awake but before anything else.
    private void OnEnable ()
    {
        m_Rigidbody.isKinematic = false;
        m_MovementInputValue = 0.0f;
        m_TurnInputValue = 0f;
    }


    private void OnDisable ()
    {
        m_Rigidbody.isKinematic = true;     // kinematic = no forces will be applied
    }


    private void Start()
    {
        m_MovementInputValue = 0f;
        m_TurnInputValue = 0f;

        // associate axis names
        m_MovementAxisName = "Vertical" + m_PlayerNumber;
        m_TurnAxisName = "Horizontal" + m_PlayerNumber;

        // reset the audio so it doesn't stack
        m_OriginalPitch = m_MovementAudio.pitch;
    }


    private void Update()
    {
        // Store the player's input and make sure the audio for the engine is playing.

        // store the values of input, runs each frame
        m_MovementInputValue = Input.GetAxis(m_MovementAxisName);

        

        m_TurnInputValue = Input.GetAxis(m_TurnAxisName);

        // check the right audio is playing
        EngineAudio();

    }

    // Play the correct audio clip based on whether or not the tank is moving and what audio is currently playing.
    private void EngineAudio()
    {
        //if tank is moving
        if ((Mathf.Abs(m_MovementInputValue) < 0.1f) && (Mathf.Abs(m_TurnInputValue) < 0.1f)) // Abs returns the absolute number so its always positive
        {
            //check audio source clip currently playing on the tank
            if (m_MovementAudio.clip == m_EngineDriving)
            {
                // we are playing the wrong clip, so change it and vary it
                m_MovementAudio.clip = m_EngineIdling;
                m_MovementAudio.pitch = Random.Range(m_OriginalPitch - m_PitchRange, m_OriginalPitch + m_PitchRange);
                m_MovementAudio.Play(); // make sure you play the clip after you've loaded it.
            }
        }
        else // not moving
        {
            // play idle
            if (m_MovementAudio.clip == m_EngineIdling)
            {
                m_MovementAudio.clip = m_EngineIdling;
                m_MovementAudio.pitch = Random.Range(m_OriginalPitch - m_PitchRange, m_OriginalPitch + m_PitchRange);
                m_MovementAudio.Play();
            }
        }
    }

    // Move and turn the tank.
    private void FixedUpdate() // runs every physics step
    {
        Move();
        Turn();
    }

    // Adjust the position of the tank based on the player's input.
    private void Move()
    {
        // define vector tank will move along
        Vector3 movement = transform.forward * m_MovementInputValue * m_Speed * Time.deltaTime;

        

        // move rigidbody to absolute position you give it (therefore use addition or current position  (relative))
        m_Rigidbody.MovePosition(m_Rigidbody.position + movement);



    }

    // Adjust the rotation of the tank based on the player's input.
    private void Turn()
    {
        // degrees to move per turn
        float turn = m_TurnInputValue * m_TurnSpeed * Time.deltaTime;

        // QUATERNIONS STORE A ROTATION
        Quaternion turnRotation = Quaternion.Euler(0f, turn, 0f);

        m_Rigidbody.MoveRotation(m_Rigidbody.rotation * turnRotation);


    }
}
